Create a program that will turn on and off an LED light with a certain frequency. More specifically, you will create a program that will turn on an LED light and keep it in this state for one second. Then it will turn it off, also for one second. This process should be repeated as long as the microprocessor is operational.

Step 1 - LEDs

You will use the LEDs available on the board. The board has a total of three LEDs, which you can use by writing the following commands in your program:
- bsp_leds_t leds;
- R_BSP_LedsGet(&leds);

The 'leds' structure contains information about the LEDs on the board, and access to them is done through the 'leds.p_leds[i]' array, where 'i' ranges from 0 to 2.

Step 2 - Super loop

Programs on microcontrollers usually run within a super loop, meaning a while loop that never stops (e.g., while(1)). Code segments that are not definitions or assignments and need to be continuously repeated should be inside the super loop. Create a super loop that contains the LED "writing" and periodicity.

Step 3 - Pin Write

To "write" to an LED, i.e., to change its voltage (0 or 1), use the following command:
- g_ioport.p_api→pinWrite(leds.p_leds[i], level);

The pinwrite() function takes as arguments the pin to be "written" to and the value (0 or 1). In the case of the board LEDs, pass the p_leds array, which is part of the leds structure and contains the three LEDs.

Note: The LED output is inverted, meaning if you input the command g_ioport.p_api→pinWrite(leds.p_leds[0], 1);, LED 0 will turn off.

Step 4 - Delay

To introduce periodicity into the program, use the R_BSP_SoftwareDelay() function. This function delays the execution of the program and takes as arguments the delay time and time units. For example, for a delay of 500ms, call the function as follows:
- R_BSP_SoftwareDelay(500,BSP_DELAY_UNITS_MILLISECONDS);

Step 5 - Compile

To compile your program, select the project folder from the list and click the build icon. The compilation progress will be displayed in the Console window.

Step 6 - Debug

If the compilation is successful, click the debug icon. You will be taken to the debug window, where you can set breakpoints and control the execution flow of the program using the Resume-Pause-Terminate tools.
