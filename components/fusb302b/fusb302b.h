#pragma once

#include "esphome/core/component.h"
#include <esphome/core/hal.h>
#include "esphome/components/i2c/i2c.h"
#include "PD_UFP.h"

namespace esphome {
    namespace fusb302b {

        class FUSB302B : public Component, public i2c::I2CDevice, public PD_UFP_c {

        public:
            FUSB302B();
            
            void set_interrupt_pin(InternalGPIOPin *interrupt_pin) { interrupt_pin_ = interrupt_pin; }
            void set_voltage(float voltage) { voltage_ = voltage; }
            
            void setup() override;
            void loop() override;
            void dump_config() override;
            
        protected:
            float voltage_;

            FUSB302_ret_t FUSB302_i2c_read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint8_t count) override;
            FUSB302_ret_t FUSB302_i2c_write(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint8_t count) override;
            // FUSB302_ret_t FUSB302_delay_ms(uint8_t) override;
            // void delay_ms(uint16_t ms) override;
            // uint16_t clock_ms(void) override;

            virtual bool read_int() override;
            virtual void write_int(bool state) override;

            InternalGPIOPin *interrupt_pin_;
        };

    }
}

