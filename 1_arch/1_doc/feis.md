# Fully Explicit Instruction Set

## Rationale

FEIS is extremely simple ISA family inspired by VLIW without any practical application in mind, just as a learning exercise. Specific FEIS-based ISA must specify available registers, execution units and how parts of instruction determine connection of registers to execution unit pins. It is supposed that one of the registers serves as instruction pointer (probably connected to the input and output of dedicated adder).

## Main ideas

1. Instruction explicitly controls multiplexers connecting registers with input and output pins of execution units
2. Some pins may be hardwared (e.g. program counter can be pinned to input and output of dedicated adder, another input determines offset to the next instruction), for others there are specific bits in in the instruction determining the registers to connect to.
3. Some bits of the instruction may be directly connected to the input of execution unit (e.g. to determine ALU operation).
4. All interaction with external devices (and system logic like MMU) is done via MMIO

## FEIS32

1. Registers and address bus are 32 bits wide
2. There are 16 registers (including program counter and special registers holding constant values)
3. Instruction is 32 bit and specifies 8 register-pin mappings

## Communication with external devices

1. Last addressable word contains a number of available devices
2. Immediately below it there are pairs of device id/device address

