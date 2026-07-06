#pragma once

#include <cstddef>
#include <filesystem>
#include <string>
#include <unordered_map>

namespace iqm::broker {

struct TargetConfig {
  std::string base_url;
  std::size_t base_url_size{};
};

struct BrokerConfig {
  std::filesystem::path socket_path;
  std::filesystem::path device_library;
  std::string symbol_prefix;
  std::string device_token;
  std::size_t device_token_size{};
  std::unordered_map<std::string, TargetConfig> target_map;
};

class ConfigLoader {
public:
  /// Loads broker config used at daemon start.
  [[nodiscard]] BrokerConfig load(const std::filesystem::path &path) const;
};

} // namespace iqm::broker
