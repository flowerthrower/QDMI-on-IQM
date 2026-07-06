#pragma once

#include "qdmi/device.h"

#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <string>
#include <vector>

namespace iqm::broker {

using AllocationId = std::string;
using JobId = std::string;
using ResourceName = std::string;
using TaskId = std::string;

enum class ALLOCATION_STATUS : std::uint8_t { ACTIVE, REVOKED };

struct AllocationRequest {
  JobId job_id;
  std::uint32_t uid{};
  std::vector<ResourceName> resources;
};

struct AllocationRef {
  ResourceName resource;
  AllocationId allocation_id;
};

struct AllocationReply {
  std::filesystem::path socket_path;
  std::vector<AllocationRef> allocations;
};

struct AllocationRecord {
  AllocationId allocation_id;
  JobId job_id;
  std::uint32_t uid{};
  ResourceName resource;
  std::filesystem::path socket_path;
  QDMI_Device_Session session{};
  ALLOCATION_STATUS status{ALLOCATION_STATUS::ACTIVE};
};

struct ProgramRequest {
  AllocationId allocation_id;
  std::string program_format;
  std::vector<std::byte> program;
  std::size_t shots{};
};

struct TaskRecord {
  AllocationId allocation_id;
  TaskId task_id;
  QDMI_Device_Job device_job{};
};

} // namespace iqm::broker
