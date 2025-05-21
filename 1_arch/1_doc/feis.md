# Fully Explicit Instruction Set

## Main ideas

1. Only register transfers are encoded (several src/dst pairs may be included in instruction)
2. Some registers are used as an input to functional units (ALU, branch, load/store)
3. One of the registers contains a content of the next instruction (and may be used as immediate value). There should be a simple way to branch over it.
4. All interaction with external devices (and system logic like MMU) is done via MMIO

## FEIS32

1. Registers and address bus are 32 bits wide
2. There are 16 registers
3. Instruction is 32 bit and contains 4 src/dst pairs

## Communication with external devices

1. Last addressable word contains a number of available devices
2. Immediately below it there are pairs of device id/device address


