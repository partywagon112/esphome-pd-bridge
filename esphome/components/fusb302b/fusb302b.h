#pragma once

#include "esphome/core/component.h"
#include <esphome/core/hal.h>

namespace esphome {
    namespace fusb302b {

        class FUSB302B : public Component {

        public:
            FUSB302B();

            void set_voltage(float voltage);
            
            void setup() override;
            void dump_config() override;
            
        protected:
            float voltage_;
        };

    }
}