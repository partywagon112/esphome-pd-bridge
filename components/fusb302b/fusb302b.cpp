#include "esphome/core/log.h"
#include "fusb302b.h"

namespace esphome {
    namespace fusb302b {

        static const char *const TAG = "FUSB302B";

        FUSB302B::FUSB302B() {
            this->init_PPS(0, PPS_V(8.4), PPS_A(2.0));
        }

        void FUSB302B::setup() {
            // this->init_PPS(FUSB302_INT_PIN, PPS_V(8.4), PPS_A(2.0));
        }

        void FUSB302B::loop() {
            this->run();
        }

        void FUSB302B::dump_config() {
            ESP_LOGCONFIG(TAG, "FUSB302B:");
            ESP_LOGCONFIG(TAG, "  Voltage: %.2f ", this->voltage_);
            LOG_PIN("  nINTERRUPT:  ", this->interrupt_pin_);
        }

        FUSB302_ret_t FUSB302B::FUSB302_i2c_read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint8_t count) {
            // count represents the number of bytes. Need routine to request
            // multiple bytes and stitch them together
            
            while (count > 0){
                *data++ = I2CDevice::read_byte(reg_addr, data);
                count--;
            }

            return count == 0 ? FUSB302_SUCCESS : FUSB302_ERR_READ_DEVICE;
        }

        FUSB302_ret_t FUSB302B::FUSB302_i2c_write(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint8_t count) {
            while (count > 0) {
                I2CDevice::write_byte(reg_addr, *data++);
                count--;
            }
            return FUSB302_SUCCESS;
        }
        
        // FUSB302_ret_t FUSB302B::FUSB302_delay_ms(uint8_t) {

        // }

        bool FUSB302B::read_int() {
            return interrupt_pin_->digital_read();
        }

        void FUSB302B::write_int(bool state) {
            interrupt_pin_->digital_write(state);
        }
    } 
} 