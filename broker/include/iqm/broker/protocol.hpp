#pragma once

#include <string_view>

namespace iqm::broker {

inline constexpr std::string_view DEVICE_BROKER_SOCKET_ENV =
    "DEVICE_BROKER_SOCKET";
inline constexpr std::string_view DEVICE_BROKER_ALLOCATIONS_ENV =
    "DEVICE_BROKER_ALLOCATIONS";

enum class BROKER_COMMAND {
  CREATE_ALLOCATIONS,
  GET_ALLOCATIONS,
  REVOKE_ALLOCATIONS,
  SUBMIT_JOB,
  CHECK_STATUS,
  GET_RESULT,
};

} // namespace iqm::broker
