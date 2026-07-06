#include "iqm/broker/broker_client.hpp"

#include <stdexcept>
#include <utility>

namespace iqm::broker {

BrokerClient::BrokerClient(std::filesystem::path socket_path)
    : socket_path_{std::move(socket_path)} {}

AllocationReply
BrokerClient::create_allocations(const AllocationRequest &) const {
  // TODO: Send create_allocations to the daemon.
  throw std::logic_error("TODO");
}

AllocationReply BrokerClient::get_allocations(const JobId &,
                                                std::uint32_t) const {
  // TODO: Send get_allocations to the daemon.
  throw std::logic_error("TODO");
}

void BrokerClient::revoke_allocations(const JobId &) const {
  // TODO: Send revoke_allocations to the daemon.
  throw std::logic_error("TODO");
}

TaskId BrokerClient::submit_job(const ProgramRequest &) const {
  // TODO: Send submit_job to the daemon.
  throw std::logic_error("TODO");
}

QDMI_Job_Status BrokerClient::check_status(const AllocationId &,
                                            const TaskId &) const {
  // TODO: Send check_status to the daemon.
  throw std::logic_error("TODO");
}

std::vector<std::byte> BrokerClient::get_result(const AllocationId &,
                                                 const TaskId &) const {
  // TODO: Send get_result to the daemon.
  throw std::logic_error("TODO");
}

} // namespace iqm::broker
