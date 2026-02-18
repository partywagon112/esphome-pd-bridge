#include "esphome/core/log.h"
#include "fusb302b.h"

namespace esphome {
    namespace fusb302b {

        static const char *const TAG = "FUSB302B";

        FUSB302B::FUSB302B() {
            // Constructor
        }

        void FUSB302B::setup() {
            // Setup code
        }

        // void FUSB302B::update() {
        //     // loop code
        // }

        void FUSB302B::dump_config() {
            ESP_LOGCONFIG(TAG, "FUSB302B:");
            ESP_LOGCONFIG(TAG, "  Voltage: %.2f ", this->voltage_);
            LOG_PIN("  nINTERRUPT:  ", this->interrupt_pin_);
        }

    } 
} 