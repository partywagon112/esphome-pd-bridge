#pragma once

#include "esphome/core/component.h"
#include <esphome/core/hal.h>
#include "esphome/components/i2c/i2c.h"

namespace esphome {
    namespace FUSB302B {

        class FUSB302B : public Component, public i2c::I2CDevice {

        public:
            FUSB302B();
            
            void set_int_pin(InternalGPIOPin *int_pin) { int_pin_ = int_pin; }
            void set_voltage(float voltage);
            
            void setup() override;
            // void update() override;
            void dump_config() override;
            
        protected:
            float voltage_;

            InternalGPIOPin *int_pin_;
        };

    }
}