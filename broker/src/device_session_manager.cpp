#include "iqm/broker/device_session_manager.hpp"

#include <stdexcept>

namespace iqm::broker {

DeviceSessionManager::DeviceSessionManager(const DeviceLibrary &device)
    : device_{device} {}

void DeviceSessionManager::initialize_device() {
  // TODO: Call configured QDMI_device_initialize symbol.
  throw std::logic_error("TODO");
}

void DeviceSessionManager::finalize_device() {
  // TODO: Call configured QDMI_device_finalize symbol.
  throw std::logic_error("TODO");
}

QDMI_Device_Session
DeviceSessionManager::create_session(const BrokerConfig &,
                                     const ResourceName &) {
  // TODO: Allocate and initialize a device session.
  throw std::logic_error("TODO");
}

QDMI_Device_Job DeviceSessionManager::submit_job(QDMI_Device_Session,
                                                 const ProgramRequest &) {
  // TODO: Create, set, and submit a device job.
  throw std::logic_error("TODO");
}

QDMI_Job_Status
DeviceSessionManager::check_job(QDMI_Device_Job) const {
  // TODO: Call configured QDMI_device_job_check symbol.
  throw std::logic_error("TODO");
}

std::vector<std::byte>
DeviceSessionManager::get_result(QDMI_Device_Job) const {
  // TODO: Call configured QDMI_device_job_get_results symbol.
  throw std::logic_error("TODO");
}

void DeviceSessionManager::free_job(QDMI_Device_Job) const {
  // TODO: Call configured QDMI_device_job_free symbol.
  throw std::logic_error("TODO");
}

void DeviceSessionManager::free_session(QDMI_Device_Session) const {
  // TODO: Call configured QDMI_device_session_free symbol.
  throw std::logic_error("TODO");
}

} // namespace iqm::broker
