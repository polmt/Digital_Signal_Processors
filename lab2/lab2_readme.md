.init g_ioport.p_api->init(g_ioport.p_cfg);

Initializing the pins according to the settings and characteristics selected in the graphical environment.


.pinCfg g_ioport.p_api->pinCfg(IOPORT_PORT_00_PIN_00,
IOPORT_CFG_IRQ_ENABLE |
IOPORT_CFG_PORT_DIRECTION_INPUT);

Setting the mode of operation for a pin.


.portDirection
Set
g_ioport.p_api->portDirectionSet(IOPORT_PORT_00,
direction_values, mask);

Setting the input/output mode for multiple pins of a port using a mask.


.pinDirectionSet
g_ioport.p_api->pinDirectionSet(IOPORT_PORT_00_
PIN_00,
IOPORT_DIRECTION_INPUT);

Setting the input/output mode for a pin.


.portRead g_ioport.p_api->portRead(IOPORT_PORT_00,
&pin_levels);

"Reads" the state of the pins on a specific port and stores the value in the variable pin_levels.


.pinRead g_ioport.p_api->pinRead(IOPORT_PORT_00_PIN_0
0, &pin_level);

"Reads" the state of a pin and stores it in the variable pin_level.


.portWrite g_ioport.p_api->portWrite(IOPORT_PORT_00,
pin_levels, mask);

Changes the state of multiple pins in a specific port using a mask.


.pinWrite g_ioport.p_api->pinWrite(IOPORT_PORT_00_PIN_0
0,
IOPORT_PIN_LEVEL_HIGH);

Changes the state of a pin.
