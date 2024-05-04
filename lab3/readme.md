### interrupt & timer/counter

Interrupts interrupt the execution of a program or process and request immediate execution of another by the processor. Using interrupts, the processor can be notified, even while executing a process, and be set to execute a higher-priority task. Interrupts can be triggered either by internal peripheral devices of the microcontroller or by external ones connected to the pins that generate interrupt requests (IRQ pin). The handling of these requests is managed by the Interrupt Handling Unit, designed to notify the processor of interrupts, taking their priority into account. The interrupt requests are serviced by the Interrupt Service Routine (ISR), which is called by the Central Processing Unit (CPU). A typical process for servicing an interrupt request is as follows: The CPU receives the request from the interrupt unit, interrupts the execution of the current program, and saves all necessary information about it in memory (program counter, data, etc.). Then, it executes the program associated with the interrupt request. Upon completion of the interrupt program, the information of the initial program is restored, and execution continues.

Interrupt management in the S7G2 microcontroller is handled by the collaboration of two units. The first is the Interrupt Controller Unit (ICU) of the microcontroller, responsible for detecting interrupts and enabling/disabling them. The detection of interrupts from external devices is performed either by the voltage level on the IRQ pins or by changes in voltage (rising edge, falling edge, rising and falling edge). Like all peripheral devices in the microcontroller, the ICU's operation can be configured using the unit's control registers. In the context of this exercise, the BSP (board support package) will be used, which allows the user to configure the operation of units through various functions and the graphical environment.

". open g_timer0.p_api->open(g_timer0.p_ctrl,g_timer0.p_cfg);

Initialization of the timer according to the configured settings.


. start g_timer0.p_api->start(g_timer0.p_ctrl);

Starts the timer measurement.


. stop g_timer0.p_api->stop(g_timer0.p_ctrl);

Stops the timer measurement.


. reset g_timer0.p_api->reset(g_timer0.p_ctrl);

Resets the timer to its initial value.


. counterGet g_timer0.p_api->counterGet(g_timer0.p_ctrl, &value);

Stores the value of the timer in the variable value.


. periodSet g_timer0.p_api->periodSet(g_timer0.p_ctrl, period, unit);

Changes the period of the timer to the specified one."
