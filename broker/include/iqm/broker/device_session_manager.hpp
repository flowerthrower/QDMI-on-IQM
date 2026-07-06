#pragma once

#include "iqm/broker/allocation.hpp"
#include "iqm/broker/broker_config.hpp"
#include "iqm/broker/device_library.hpp"

#include "qdmi/device.h"

#include <vector>

namespace iqm::broker {

class DeviceSessionManager {
public:
  /// Uses the configured device library.
  explicit DeviceSessionManager(const DeviceLibrary &device);
  /// Initializes the configured device once.
  void initialize_device();
  /// Finalizes the configured device once.
  void finalize_device();

  /// Creates a device session for one QPU.
  [[nodiscard]] QDMI_Device_Session
  create_session(const BrokerConfig &config, const ResourceName &resource);
  /// Submits one program through the configured device.
  [[nodiscard]] QDMI_Device_Job submit_job(QDMI_Device_Session session,
                                           const ProgramRequest &request);
  /// Checks one device job.
  [[nodiscard]] QDMI_Job_Status check_job(QDMI_Device_Job job) const;
  /// Gets one device job result.
  [[nodiscard]] std::vector<std::byte> get_result(QDMI_Device_Job job) const;
  /// Frees one device job.
  void free_job(QDMI_Device_Job job) const;
  /// Frees one device session.
  void free_session(QDMI_Device_Session session) const;

private:
  const DeviceLibrary &device_;
};

} // namespace iqm::broker
