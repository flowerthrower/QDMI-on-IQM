include(GNUInstallDirs)

set(BUILD_DEVICE_BROKER_CORE_TARGET device-broker-core)
set(BUILD_DEVICE_BROKER_DAEMON_TARGET device-brokerd)
set(BUILD_DEVICE_BROKER_CTL_TARGET device-brokerctl)

add_library(${BUILD_DEVICE_BROKER_CORE_TARGET} STATIC)
target_compile_features(${BUILD_DEVICE_BROKER_CORE_TARGET} PRIVATE cxx_std_20)
target_include_directories(${BUILD_DEVICE_BROKER_CORE_TARGET}
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(
  ${BUILD_DEVICE_BROKER_CORE_TARGET}
  PROPERTIES POSITION_INDEPENDENT_CODE ON
             C_VISIBILITY_PRESET hidden
             CXX_VISIBILITY_PRESET hidden
             VISIBILITY_INLINES_HIDDEN 1)
target_sources(
  ${BUILD_DEVICE_BROKER_CORE_TARGET}
  PRIVATE src/allocation_store.cpp
          src/broker_client.cpp
          src/broker_config.cpp
          src/broker_daemon.cpp
          src/broker_server.cpp
          src/device_library.cpp
          src/device_session_manager.cpp
  PUBLIC include/iqm/broker/allocation.hpp
         include/iqm/broker/allocation_store.hpp
         include/iqm/broker/broker_client.hpp
         include/iqm/broker/broker_config.hpp
         include/iqm/broker/broker_daemon.hpp
         include/iqm/broker/broker_server.hpp
         include/iqm/broker/protocol.hpp
         include/iqm/broker/device_library.hpp
         include/iqm/broker/device_session_manager.hpp)
target_link_libraries(${BUILD_DEVICE_BROKER_CORE_TARGET}
                      PUBLIC qdmi::qdmi
                      PRIVATE qdmi::qdmi_project_warnings)

add_executable(${BUILD_DEVICE_BROKER_DAEMON_TARGET} src/daemon_main.cpp)
target_compile_features(${BUILD_DEVICE_BROKER_DAEMON_TARGET} PRIVATE cxx_std_20)
target_link_libraries(${BUILD_DEVICE_BROKER_DAEMON_TARGET}
                      PRIVATE ${BUILD_DEVICE_BROKER_CORE_TARGET})

add_executable(${BUILD_DEVICE_BROKER_CTL_TARGET} src/brokerctl_main.cpp)
target_compile_features(${BUILD_DEVICE_BROKER_CTL_TARGET} PRIVATE cxx_std_20)
target_link_libraries(${BUILD_DEVICE_BROKER_CTL_TARGET}
                      PRIVATE ${BUILD_DEVICE_BROKER_CORE_TARGET})

add_custom_target(device-broker
                  DEPENDS ${BUILD_DEVICE_BROKER_DAEMON_TARGET}
                          ${BUILD_DEVICE_BROKER_CTL_TARGET})

# device-broker-server: daemon and broker config for the service node.
set(DEVICE_BROKER_CONFIG_DIR
    "/etc/device-broker"
    CACHE PATH "Install directory for the device broker config")
set(DEVICE_BROKER_RUNTIME_DIR
    "/run/device-broker"
    CACHE PATH "Runtime directory for the device broker")
set(DEVICE_BROKER_SYSTEMD_DIR
    "/usr/lib/systemd/system"
    CACHE PATH "Install directory for the device broker systemd unit")

# device-broker-slurm: prolog and epilog files for Slurm nodes.
set(DEVICE_BROKER_SLURM_LIBEXEC_DIR
    "/usr/libexec/device-broker"
    CACHE PATH "Install directory for device broker Slurm hook scripts")
set(DEVICE_BROKER_SLURM_CONF_DIR
    "/etc/slurm"
    CACHE PATH "Install directory for device broker Slurm config examples")

configure_file(config/device-broker.toml.in device-broker.toml @ONLY)
configure_file(systemd/device-brokerd.service.in device-brokerd.service @ONLY)
configure_file(slurm/device-broker-prolog.in device-broker-prolog @ONLY)
configure_file(slurm/device-broker-epilog.in device-broker-epilog @ONLY)
configure_file(slurm/device-broker.conf.in device-broker.conf @ONLY)

# device-broker-server
install(
  TARGETS ${BUILD_DEVICE_BROKER_DAEMON_TARGET}
  RUNTIME DESTINATION ${CMAKE_INSTALL_SBINDIR}
          COMPONENT device-broker-server)

# device-broker-client
install(
  TARGETS ${BUILD_DEVICE_BROKER_CTL_TARGET}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
          COMPONENT device-broker-client)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/device-broker.toml
        DESTINATION ${DEVICE_BROKER_CONFIG_DIR}
        COMPONENT device-broker-server)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/device-brokerd.service
        DESTINATION ${DEVICE_BROKER_SYSTEMD_DIR}
        COMPONENT device-broker-server)

# device-broker-slurm
install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/device-broker-prolog
                 ${CMAKE_CURRENT_BINARY_DIR}/device-broker-epilog
        DESTINATION ${DEVICE_BROKER_SLURM_LIBEXEC_DIR}
        COMPONENT device-broker-slurm)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/device-broker.conf
        DESTINATION ${DEVICE_BROKER_SLURM_CONF_DIR}
        COMPONENT device-broker-slurm)
