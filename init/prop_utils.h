#include <string>

namespace prop_utils {
    void property_override(char const prop[], char const value[]);
    void property_override_triple(char const system_prop[], char const vendor_prop[], char const system_prop_other[], char const value[]);
    bool check_device(const std::string& device);
}
