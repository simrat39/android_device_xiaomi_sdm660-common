#include <fstream>
#include <string>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <android-base/properties.h>
#include "property_service.h"

using android::init::property_set;

namespace prop_utils {

    void property_override(char const prop[], char const value[])
    {
        prop_info *pi;

        pi = (prop_info*) __system_property_find(prop);
        if (pi)
            __system_property_update(pi, value, strlen(value));
        else
            __system_property_add(prop, strlen(prop), value, strlen(value));
    }

    void property_override_triple(char const system_prop[], char const vendor_prop[], char const system_prop_other[], char const value[])
    {
        property_override(system_prop, value);
        property_override(vendor_prop, value);
        property_override(system_prop_other, value);
    }

    bool check_device(const std::string& device)
    {
        std::ifstream fin("/proc/cmdline");
        std::string buffer;
        std::getline(fin,buffer);
        fin.close();

        if (buffer.find(device) != std::string::npos) return true;
        return false;
    }


}
