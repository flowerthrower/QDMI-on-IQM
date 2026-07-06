#include "iqm/broker/broker_daemon.hpp"

#include <stdexcept>
#include <utility>

namespace iqm::broker {

BrokerDaemon::BrokerDaemon(BrokerConfig config)
    : config_{std::move(config)}, sessions_{device_},
      server_{config_.socket_path} {}

int BrokerDaemon::run() {
  // TODO: Load configured device and start the socket server.
  throw std::logic_error("TODO");
}

void BrokerDaemon::stop() {
  // TODO: Stop server and free device state.
  throw std::logic_error("TODO");
}

void BrokerDaemon::recover_state() {
  // TODO: Recover active allocations and cleanup state.
  throw std::logic_error("TODO");
}

AllocationReply
BrokerDaemon::create_allocations(const AllocationRequest &) {
  // TODO: Create sessions and save allocations.
  throw std::logic_error("TODO");
}

AllocationReply BrokerDaemon::get_allocations(const JobId &,
                                                std::uint32_t) const {
  // TODO: Return socket and allocation map.
  throw std::logic_error("TODO");
}

void BrokerDaemon::revoke_allocations(const JobId &) {
  // TODO: Free jobs, free sessions, and revoke allocations.
  throw std::logic_error("TODO");
}

TaskId BrokerDaemon::submit_job(const ProgramRequest &, std::uint32_t) {
  // TODO: Authorize, create device job, submit it, and save task.
  throw std::logic_error("TODO");
}

QDMI_Job_Status BrokerDaemon::check_status(const AllocationId &,
                                            const TaskId &,
                                            std::uint32_t) const {
  // TODO: Authorize and check device job status.
  throw std::logic_error("TODO");
}

std::vector<std::byte> BrokerDaemon::get_result(const AllocationId &,
                                                 const TaskId &,
                                                 std::uint32_t) const {
  // TODO: Authorize and fetch device job result.
  throw std::logic_error("TODO");
}

std::filesystem::path
BrokerDaemon::make_job_socket_path(const JobId &) const {
  // TODO: Build the per-job socket path.
  throw std::logic_error("TODO");
}

AllocationId BrokerDaemon::make_allocation_id() const {
  // TODO: Generate a new allocation id.
  throw std::logic_error("TODO");
}

TaskId BrokerDaemon::make_task_id() const {
  // TODO: Generate a new task id.
  throw std::logic_error("TODO");
}

} // namespace iqm::broker
