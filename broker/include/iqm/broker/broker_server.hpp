#pragma once

#include "iqm/broker/allocation.hpp"

#include <cstdint>
#include <filesystem>

namespace iqm::broker {

struct PeerCredentials {
  std::uint32_t pid{};
  std::uint32_t uid{};
  std::uint32_t gid{};
};

class BrokerServer {
public:
  /// Stores the socket path to serve.
  explicit BrokerServer(std::filesystem::path socket_path);

  /// Starts the Unix socket server.
  void start();
  /// Stops the Unix socket server.
  void stop();

private:
  /// Accepts one broker client.
  void accept_client();
  /// Handles prolog allocation creation.
  void handle_create_allocations();
  /// Handles SPANK allocation lookup.
  void handle_get_allocations();
  /// Handles epilog cleanup.
  void handle_revoke_allocations();
  /// Handles job submit.
  void handle_submit_job();
  /// Handles job status.
  void handle_check_status();
  /// Handles job result.
  void handle_get_result();
  /// Reads peer uid for authorization.
  [[nodiscard]] PeerCredentials read_peer_credentials(int fd) const;

  std::filesystem::path socket_path_;
};

} // namespace iqm::broker
