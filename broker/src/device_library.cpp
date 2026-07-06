#include "iqm/broker/device_library.hpp"

#include <stdexcept>

namespace iqm::broker {

void DeviceLibrary::load(const std::filesystem::path &,
                         const std::string &) {
  // TODO: Open the device library and resolve prefixed symbols.
  throw std::logic_error("TODO");
}

const DeviceSymbols &DeviceLibrary::symbols() const {
  // TODO: Return loaded symbols after load() succeeds.
  throw std::logic_error("TODO");
}

} // namespace iqm::broker
