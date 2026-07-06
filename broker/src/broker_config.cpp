#include "iqm/broker/broker_config.hpp"

#include <stdexcept>

namespace iqm::broker {

BrokerConfig ConfigLoader::load(const std::filesystem::path &) const {
  // TODO: Load socket_path, device_library, symbol_prefix, token, and targets.
  throw std::logic_error("TODO");
}

} // namespace iqm::broker
