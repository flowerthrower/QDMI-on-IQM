#include "iqm/broker/allocation_store.hpp"

#include <stdexcept>

namespace iqm::broker {

void AllocationStore::save_allocation(const AllocationRecord &) {
  // TODO: Save active allocation state.
  throw std::logic_error("TODO");
}

std::vector<AllocationRecord>
AllocationStore::get_allocations(const JobId &, std::uint32_t) const {
  // TODO: Return active allocations for the job and user.
  throw std::logic_error("TODO");
}

std::optional<AllocationRecord>
AllocationStore::lookup_allocation(const AllocationId &) const {
  // TODO: Find one allocation.
  throw std::logic_error("TODO");
}

bool AllocationStore::authorize(std::uint32_t, const AllocationId &) const {
  // TODO: Check peer uid against allocation owner.
  throw std::logic_error("TODO");
}

void AllocationStore::save_task(const TaskRecord &) {
  // TODO: Save device job state.
  throw std::logic_error("TODO");
}

std::optional<TaskRecord>
AllocationStore::lookup_task(const AllocationId &, const TaskId &) const {
  // TODO: Find one task.
  throw std::logic_error("TODO");
}

void AllocationStore::revoke_job(const JobId &) {
  // TODO: Mark all job allocations revoked.
  throw std::logic_error("TODO");
}

} // namespace iqm::broker
