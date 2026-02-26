#include "esphome/core/log.h"
#include "fusb302b.h"

namespace esphome {
    namespace fusb302b {

        static const char *const TAG = "FUSB302B";

        FUSB302B::FUSB302B() {
            // Constructor
        }

        void FUSB302B::setup() {
            tcpm_init(0);
            delayMicroseconds(1000*50);
            pd_init(0);
            delayMicroseconds(1000*50);
        }

        void FUSB302B::loop() {
            if (0 == interrupt_pin_.digitalRead()) {
                tcpc_alert(0);
            }

            pd_run_state_machine(0);
            // For some reason, a delay of 4 ms seems to be best
            // My guess is that spamming the I2C bus too fast causes problems
            delayMicroseconds(1000*4);
        }

        void FUSB302B::dump_config() {
            ESP_LOGCONFIG(TAG, "FUSB302B:");
            ESP_LOGCONFIG(TAG, "  Voltage: %.2f ", this->voltage_);
            LOG_PIN("  nINTERRUPT:  ", this->interrupt_pin_);
        }

    } 
} 