#include "esphome/core/log.h"
#include "fusb302b.h"

namespace esphome {
namespace my_external_component {

static const char *const TAG = "FUSB302B";

FUSB302B::FUSB302B() {
    // Constructor
}

void FUSB302B::set_voltage(float voltage) { voltage_ = voltage; }

void FUSB302B::setup() {
    // Setup code
}

void FUSB302B::update() {
    // loop code
}

void FUSB302B::dump_config() {
    ESP_LOGCONFIG(TAG, "FUSB302B:");
    LOG_PIN("  Voltage:  ", this->voltage_);
}

}  // namespace my_external_component
}  // namespace esphome