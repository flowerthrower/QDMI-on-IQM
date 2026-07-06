#pragma once

#include "iqm/broker/allocation.hpp"

#include <cstdint>
#include <optional>
#include <vector>

namespace iqm::broker {

class AllocationStore {
public:
  /// Stores an allocation so jobs can use it later.
  void save_allocation(const AllocationRecord &record);
  /// Lists job allocations for SPANK env injection.
  [[nodiscard]] std::vector<AllocationRecord>
  get_allocations(const JobId &job_id, std::uint32_t uid) const;
  /// Finds one allocation for submit/status/result.
  [[nodiscard]] std::optional<AllocationRecord>
  lookup_allocation(const AllocationId &allocation_id) const;
  /// Checks caller ownership before device access.
  [[nodiscard]] bool authorize(std::uint32_t uid,
                               const AllocationId &allocation_id) const;
  /// Stores a submitted task for later status/result.
  void save_task(const TaskRecord &record);
  /// Finds one task for status/result.
  [[nodiscard]] std::optional<TaskRecord>
  lookup_task(const AllocationId &allocation_id, const TaskId &task_id) const;
  /// Revokes all allocations for epilog cleanup.
  void revoke_job(const JobId &job_id);
};

} // namespace iqm::broker
