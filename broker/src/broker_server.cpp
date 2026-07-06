#include "iqm/broker/broker_server.hpp"

#include <stdexcept>
#include <utility>

namespace iqm::broker {

BrokerServer::BrokerServer(std::filesystem::path socket_path)
    : socket_path_{std::move(socket_path)} {}

void BrokerServer::start() {
  // TODO: Bind Unix socket and accept clients.
  throw std::logic_error("TODO");
}

void BrokerServer::stop() {
  // TODO: Close socket and unlink socket path.
  throw std::logic_error("TODO");
}

void BrokerServer::accept_client() {
  // TODO: Accept one client.
  throw std::logic_error("TODO");
}

void BrokerServer::handle_create_allocations() {
  // TODO: Decode create_allocations request.
  throw std::logic_error("TODO");
}

void BrokerServer::handle_get_allocations() {
  // TODO: Decode get_allocations request.
  throw std::logic_error("TODO");
}

void BrokerServer::handle_revoke_allocations() {
  // TODO: Decode revoke_allocations request.
  throw std::logic_error("TODO");
}

void BrokerServer::handle_submit_job() {
  // TODO: Decode submit_job request.
  throw std::logic_error("TODO");
}

void BrokerServer::handle_check_status() {
  // TODO: Decode check_status request.
  throw std::logic_error("TODO");
}

void BrokerServer::handle_get_result() {
  // TODO: Decode get_result request.
  throw std::logic_error("TODO");
}

PeerCredentials BrokerServer::read_peer_credentials(int) const {
  // TODO: Read peer uid from the Unix socket.
  throw std::logic_error("TODO");
}

} // namespace iqm::broker
