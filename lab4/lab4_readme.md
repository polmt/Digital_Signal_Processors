Pulse Width Modulation (PWM) is a technique for representing values between 0 and 1 (maximum voltage) in a digital system. The operation of PWM involves rapidly switching between the states of 0 and 1 at such a rate that the device at the output cannot fully respond to this change. The time during which the signal is in the state of 1, within one PWM cycle, is called the duty cycle, and the voltage perceived by the output depends on it.

The embedded peripheral units of microcontrollers have control registers, which can be configured and used in applications. The fields of these registers control the various functions of each unit.

The control registers are memory-mapped, meaning there are reserved memory locations for each of them. Writing to the fields of a register is done by writing to the memory address corresponding to that register. Using pointers is necessary for writing to memory locations. For example, in an application where writing to register Reg is required, which has a memory address of 0x4004085C, a pointer must be defined as follows:

uint32_t *reg_ptr = (uint32_t *) 0x4004085C;

The uint32_t type is for unsigned 32-bit integers, and similarly, there are types for 8 and 16 bits (uint8_t, uint16_t). Assigning values to pointers is done as usual:

*reg_ptr = 0x0000008F;

Values can also be assigned using a bit mask. Using masks allows changing specific bits or fields in the register without needing to recalculate the value. Masks are sequences of bits that, when applied to a register with some logical operation (AND, OR, etc.), can change the value in specific bits of the register. Left shift operation is used in C language to create masks. For example, to create a mask 0b0010, one left shift operation of value 1 is sufficient, like this: mask = (1 << 1). The value to the left of the '<<' operator indicates the value to be shifted, while the value to the right indicates how many times.

Examples of creating masks with left shift are as follows:

Now let's see how using masks can change specific bits in the register. Suppose we have a 4-bit register with an initial value of 0b1001 and a mask 0b0010 (1 << 1). If we perform the logical OR operation between the mask and the register, the value 0b1011 will result. We observe that the action of this mask changes bit 1 from 0 to 1 while simultaneously keeping the remaining bits the same. Thus, to change a specific bit from 0 to 1 in the value of a register, it is sufficient to act with a mask that will have 1 in the position we want to modify. The command should be as follows:

*reg_ptr |= (1<<1);

To zero out a bit of a register, we need to act accordingly with a mask. In the previous example, if we want to zero out bit 3, then we should use the mask 0b0111 and act with the AND operation. The operation "1 and 0" always gives 0, while the operation "X and 1" always gives X. To create the mask, we use left shift and the NOT operator '~' as follows: mask = ~(1<<3). Left shift creates the mask 0b1000, and the NOT operator '~' reverses the bits. The command to zero out bit 3 in the register of the example should be as follows:

*reg_ptr &= ~ (1<<3);

For creating more complex masks, the following format can be used:

0b10001010: (1<<1 | 1<<3 | 1<<7)




1) Initially, the channels of the GPT unit are disabled. Activate channels 8-13 of the GPT unit by writing the value '0' to bit 6 of the MSTPCRD register (module stop control register D). This register is located at memory address 0x40047008 and is responsible for disabling units to achieve lower power consumption on the microcontroller. Confirm that the value '0' in bit 6 activates channels 8-13 by referring to the register description in chapter 11.2 of the manual.
2) In the context of this exercise, use channel 8 and configure it so that the counter of the channel starts from 0 and increases. The register responsible for this setting is the GTUDDTYC (general PWM timer count direction and duty setting register), and each channel has such a register. Specifically, for channel 8, the corresponding register is located at memory address 0x40078830. For the required configuration, bit 0 of the register must have the value '1' while the remaining bits must have the value '0'. Confirm the "direction" of the counter by searching for the register in chapter 23.2 of the manual.
3) Set the GTPR register (general PWM timer cycle setting register) to the value 119999 or 0x1D4BF. The register is located at address 0x40078864. This register is the corresponding limit register of the simple architecture of the previous section and contains the number of cycles corresponding to a 1ms period (1 KHz frequency). The calculation of the number of cycles arises from the information that the unit operates with the PCKLD clock, which has a frequency of 120 MHz. One clock cycle lasts 8.33333..ns and in a period of 1ms (PWM period), there are 120000 cycles. Because counting starts from 0, the value of the GTPR register should be 120000 - 1.
4) Properly configure the GTCCRA register (general PWM timer compare capture register A), which is the corresponding match register of the simple architecture and contains the number of cycles corresponding to the duty cycle. The register is located at address 0x4007884c and its value is calculated based on the duty cycle.
5) Next, you should configure the output function for the channel. As we saw in the simple architecture of the previous section, we want the output of the channel to initially be in the '1' state, to become '0' when the counter reaches the value in the GTCCRA register (duty cycle), and finally to return to the '1' state at the end of the PWM period. The register that configures the output function is the GTIOR (general PWM timer I/O control register), and for channel 8, its memory address is 0x40078834. Specifically, the OAE field must be properly configured to enable the output, while the GTIOA field that defines the output function should be configured with the appropriate value to perform the output function defined above. Find the values that the fields should have in the register description in chapter 23.2.14 of the manual.
6) To start the counter on the channel, the CST field (bit 0) of the GTCR register (general PWM timer control register) must be set to '1'. The GTCR register corresponding to channel 8 has a memory address of 0x4007882c.
7) Finally, connect the output of the channel to the pin to which it corresponds. Channel 8 corresponds to pin p107 and to connect it, you need to modify the PWPR (write protect register) and P107PFS (port 107 pin function select register) registers, which are located at addresses 0x40040d03 and 0x4004085C, respectively. PWPR is an 8-bit register that allows or prevents writing to registers that configure pin functions. First, it must be set to the value '0', and immediately after to the value '0x40' to allow writing to the P107PFS register. The P107PFS register contains 32 bits and configures the function of pin 07 of port 1. For connection to the output of the channel, bit 16 must be set to the value '1', and bits 28-24 must be set to the value 0b00011.
