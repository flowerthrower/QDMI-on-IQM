#pragma once

#include "iqm/broker/allocation.hpp"

#include <cstdint>
#include <filesystem>
#include <vector>

namespace iqm::broker {

class BrokerClient {
public:
  /// Stores the broker socket path.
  explicit BrokerClient(std::filesystem::path socket_path);

  /// Asks daemon to create job allocations.
  [[nodiscard]] AllocationReply
  create_allocations(const AllocationRequest &request) const;
  /// Asks daemon for allocations to inject.
  [[nodiscard]] AllocationReply get_allocations(const JobId &job_id,
                                                 std::uint32_t uid) const;
  /// Asks daemon to cleanup a job.
  void revoke_allocations(const JobId &job_id) const;
  /// Sends a program to the daemon.
  [[nodiscard]] TaskId submit_job(const ProgramRequest &request) const;
  /// Reads task status through the daemon.
  [[nodiscard]] QDMI_Job_Status check_status(
      const AllocationId &allocation_id, const TaskId &task_id) const;
  /// Reads task result through the daemon.
  [[nodiscard]] std::vector<std::byte> get_result(
      const AllocationId &allocation_id, const TaskId &task_id) const;

private:
  std::filesystem::path socket_path_;
};

} // namespace iqm::broker
