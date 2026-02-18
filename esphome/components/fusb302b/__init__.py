import esphome.config_validation as cv
import esphome.codegen as cg
from esphome.const import (
    CONF_ID,
    CONF_VOLTAGE,
    CONF_INTERRUPT_PIN
)
from esphome import pins

CODEOWNERS = ["@partywagon112"]

# C++ namespace
ns = cg.esphome_ns.namespace("fusb302b")
FUSB302B = ns.class_("FUSB302B", cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(FUSB302B),
    cv.Required(CONF_INTERRUPT_PIN): pins.internal_gpio_input_pin_schema,
    cv.Required(CONF_VOLTAGE): cv.float_
    # Schema definition, containing the options available for the component
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    pin = await cg.gpio_pin_expression(config[CONF_INTERRUPT_PIN])
    cg.add(var.set_int_pin(pin))
    cg.add(var.set_voltage(config[CONF_VOLTAGE]))