Activation and Configuration of the ADC Module in the Graphical Environment.

To use the ADC module in an application, you must follow the steps below.
- Select the "Threads" tab from the "Synergy Configuration" tab bar.
- To add the appropriate stack, select "New Stack", "Driver", "Analog", "ADC driver on r_adc" as shown in the photo below.
- From the "Threads" tab, select the stack defined in the previous step.
- Then select the "Properties" tab. Here you can change the settings for the adc unit.
- Click on "Generate Project Content". This will generate the necessary files for using the stack and automatically import them into your project folder.

Here is a brief explanation of the fields in the properties tab:
1. The "Parameter Checkings" field concerns whether the code for parameter checking is included in the application.
2. The "Name" field concerns the name of the module to be used.
3. The "Unit" field concerns the adc unit to be used. The S7G2 board has 2 units, 0 and 1.
4. The "Resolution" field concerns the resolution of the measurement result of the unit, i.e., the size of the result in bits.
5. The "Alignment" field concerns the alignment of the result.
6. The "Clear after read" field concerns whether the result register will be cleared after reading the result. If enabled, monitoring the value of the register with the debugger will always result in 0.
7. The "Mode" field concerns the operating mode of the adc unit defined above.
-- Single scan: Converts the analog input of the selected channel once per execution. The conversion is performed successively in ascending order, based on the number of each channel.
-- Continuous scan: Converts the analog input of the selected channels once per execution. The conversion is performed successively in ascending order, based on the number of each channel.
-- Group Scan: Allows the user to assign channels to one of two groups (A or B). The conversion of the analog input of the channels of each group is performed successively in ascending order, based on the number of each channel, when a command to activate the specific group is received.
8. The "Channels 0-27" field concerns the number of channels to be used.
-- If Normal mode is selected: Concerns the channels to be used in the adc unit.
-- If Group mode is selected: Concerns which group the respective channel belongs to.
9. The Temperature/Voltage Sensor fields concern whether and in which group the temperature and voltage sensors will be used, respectively.
10. The "Scan Mask Group B" field concerns which channels belong to Group B. Note! It is only used in group mode, and the channels defined here should not belong to Group A.
11. The "Normal/Group A Trigger" field concerns the type of activation of the unit. If group mode is enabled, this option is used to set the activation of Group A.
12. The "Group B Trigger" field concerns the type of activation of group B.
13. The "Group priority" field sets the interaction mode of the 2 groups. For example, if a measurement of group B stops when a measurement of group A is activated. This field only makes sense when group mode is enabled.
14. The "Add/Average count" field indicates whether addition or averaging will be performed between the values of a number of channels of the unit.
15. The "Channels 0-27" field concerns which channels will be used for the above operation. This field only makes sense when the above operation is enabled.
16. The Temperature/Voltage Sensor fields concern whether the temperature/voltage sensors will be used for addition or averaging operations.
17. The "Channels 0-2" field concerns which channels use the updated values of the sample and hold.
18. The "Sample hold states" field concerns the number of states for the above operation.
19. The "Callback" field concerns whether a user callback function will be used at the end of the measurements. If used, it is called via Interrupts each time a measurement of the adc unit is completed.
20. The "Scan end interrupt priority" field concerns the priority of the interrupt that will be executed at the end of the measurement.
21. The "Scan end Group B interrupt priority" field concerns the priority of the interrupt that will be executed at the end of the measurement of group B.


.open g_adc.p_api->open(g_adc.p_ctrl, g_adc.p_cfg);


Initializes the ADC unit. It sets the operation mode, activation sources, interrupt priorities, and channel and sensor settings.


.scanCfg g_adc.p_api->scanCfg(g_adc.p_ctrl, g_adc.p_channel_cfg);


Configures the channels, groups, and the measurement activation mode that the unit defined with the open command will use.


.scanStart g_adc.p_api->scanStart(g_adc.p_ctrl);


Starts the measurements.


.scanStop g_adc.p_api->scanStop(g_adc.p_ctrl);


Stops the measurements.


.read g_adc.p_api->read(g_adc.p_ctrl, ADC_REG_CHANNEL_13, &adc_data);


Used to read the conversion result of the adc unit measurement.


.sampleStateCountSet g_adc.p_api-> sampleStateCountSet(g_adc.p_ctrl,&adc_sample);


Sets the sampling states of the specific channel.


.close g_adc.p_api->close(g_adc.p_ctrl);


Stops the operation of the specific adc unit.


Interrupts any ongoing measurements.


The procedure for using the unit in an application is as follows:


.scanStatusGet g_adc.p_api->scanStatusGet(g_adc.p_ctrl);


Checks the status of the measurement.
