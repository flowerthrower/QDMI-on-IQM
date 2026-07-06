#pragma once

#include "qdmi/device.h"

#include <cstddef>
#include <filesystem>
#include <string>

namespace iqm::broker {

struct DeviceSymbols {
  int (*initialize)(){};
  int (*finalize)(){};
  int (*session_alloc)(QDMI_Device_Session *){};
  int (*session_set_parameter)(QDMI_Device_Session,
                               QDMI_Device_Session_Parameter, std::size_t,
                               const void *){};
  int (*session_init)(QDMI_Device_Session){};
  void (*session_free)(QDMI_Device_Session){};
  int (*create_job)(QDMI_Device_Session, QDMI_Device_Job *){};
  int (*job_set_parameter)(QDMI_Device_Job, QDMI_Device_Job_Parameter,
                           std::size_t, const void *){};
  int (*job_submit)(QDMI_Device_Job){};
  int (*job_check)(QDMI_Device_Job, QDMI_Job_Status *){};
  int (*job_get_results)(QDMI_Device_Job, QDMI_Job_Result, std::size_t, void *,
                         std::size_t *){};
  void (*job_free)(QDMI_Device_Job){};
};

class DeviceLibrary {
public:
  /// Loads a configured device library.
  void load(const std::filesystem::path &library_path,
            const std::string &symbol_prefix);
  /// Provides resolved interface function pointers.
  [[nodiscard]] const DeviceSymbols &symbols() const;

private:
  DeviceSymbols symbols_{};
};

} // namespace iqm::broker
