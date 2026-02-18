#include "esphome/core/log.h"
#include "fusb302b.h"

namespace esphome {
namespace my_external_component {

static const char *const TAG = "FUSB302B";

fusb302b::FUSB302B() {
    // Constructor
}

void fusb302b::set_voltage(float voltage) { voltage_ = voltage; }

void fusb302b::setup() {
    // Setup code
}

// void fusb302b::update() {
//     // loop code
// }

void fusb302b::dump_config() {
    ESP_LOGCONFIG(TAG, "FUSB302B:");
    LOG_PIN("  Voltage:  ", this->voltage_);
}

}  // namespace my_external_component
}  // namespace esphome