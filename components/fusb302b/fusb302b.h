#pragma once

#include "esphome/core/component.h"
#include <esphome/core/hal.h>
#include "esphome/components/i2c/i2c.h"
#include "FUSB302_UFP.h"

namespace esphome {
    namespace fusb302b {

        class FUSB302B : public Component, public i2c::I2CDevice {

        public:
            FUSB302B();
            
            void set_interrupt_pin(InternalGPIOPin *interrupt_pin) { interrupt_pin_ = interrupt_pin; }
            void set_voltage(float voltage) { voltage_ = voltage; }
            
            void setup() override;
            void loop() override;
            void dump_config() override;
            
        protected:
            float voltage_;

            InternalGPIOPin *interrupt_pin_;
        };

    }
}