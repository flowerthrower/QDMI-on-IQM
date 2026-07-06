#pragma once

#include "iqm/broker/allocation.hpp"
#include "iqm/broker/allocation_store.hpp"
#include "iqm/broker/broker_config.hpp"
#include "iqm/broker/broker_server.hpp"
#include "iqm/broker/device_library.hpp"
#include "iqm/broker/device_session_manager.hpp"

#include <cstdint>
#include <vector>

namespace iqm::broker {

class BrokerDaemon {
public:
  /// Keeps config and broker state together.
  explicit BrokerDaemon(BrokerConfig config);

  /// Starts the daemon for broker calls.
  int run();
  /// Stops daemon and frees device state.
  void stop();
  /// Rebuilds state after daemon restart.
  void recover_state();

  /// Creates device sessions for a Slurm job.
  [[nodiscard]] AllocationReply
  create_allocations(const AllocationRequest &request);
  /// Returns job allocations for env injection.
  [[nodiscard]] AllocationReply get_allocations(const JobId &job_id,
                                                 std::uint32_t uid) const;
  /// Frees device jobs and sessions.
  void revoke_allocations(const JobId &job_id);
  /// Submits a program through an allocation.
  [[nodiscard]] TaskId submit_job(const ProgramRequest &request,
                                   std::uint32_t uid);
  /// Checks one submitted device job.
  [[nodiscard]] QDMI_Job_Status check_status(
      const AllocationId &allocation_id, const TaskId &task_id,
      std::uint32_t uid) const;
  /// Gets result for one submitted job.
  [[nodiscard]] std::vector<std::byte> get_result(
      const AllocationId &allocation_id, const TaskId &task_id,
      std::uint32_t uid) const;

private:
  /// Builds the job-local socket path.
  [[nodiscard]] std::filesystem::path make_job_socket_path(
      const JobId &job_id) const;
  /// Creates an id for one allocation.
  [[nodiscard]] AllocationId make_allocation_id() const;
  /// Creates an id for one task.
  [[nodiscard]] TaskId make_task_id() const;

  BrokerConfig config_;
  AllocationStore store_;
  DeviceLibrary device_;
  DeviceSessionManager sessions_;
  BrokerServer server_;
};

} // namespace iqm::broker
