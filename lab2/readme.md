Develop an application in which you will use the I/O Ports. In the application, you will use LED lights and switches S4, S5 of the board. The application should "read" the state of the switches and accordingly power the corresponding LEDs. More specifically, the operation of the application should be as follows:
- If switch S4 is pressed, then Led1 will turn on.
- If switch S5 is pressed, then Led2 will turn on.
- If both switches S4 and S5 are pressed, then Led3 will turn on.

Create a new project according to the instructions of Exercise 1 and develop your application in the 'hal_entry.c' file. Your application should initially define the function (input/output) of the terminals connected to the devices you will use in this exercise. The mapping is as follows:
- Led1: port6, pin0 (IOPORT_PORT_06_PIN_00)
- Led2: port6, pin1 (IOPORT_PORT_06_PIN_01)
- Led3: port6, pin2 (IOPORT_PORT_06_PIN_02)
- Button S4: port0, pin6 (IOPORT_PORT_00_PIN_06)
- Button S5: port5, pin5 (IOPORT_PORT_00_PIN_05)

To define the function, use the pinDirectionSet() function. Then create a super-loop that will read the level of the switches and will light up the corresponding LEDs. To read the voltage level on the switches, use the pinRead() function. To light up an LED, use the pinWrite() function. We remind you that a pressed switch is in the '0' state and that to light up a board LED, it must be in the '0' state.


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
