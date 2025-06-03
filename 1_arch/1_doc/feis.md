# Fully Explicit Instruction Set

## Rationale

FEIS is extremely simple ISA family inspired by VLIW without any practical application in mind, just as a learning exercise. Specific FEIS-based ISA must specify connection of registers to execution units and actual prrocedure of instruction fetch and execution. It is supposed that one of the registers serves as instruction pointer (probably connected to the input and output of dedicated adder).

## Main ideas

1. Only register transfers are encoded (several src/dst pairs may be included in instruction) [^1]
2. Some registers are used as an input and output to functional units (ALU, branch, load/store). Output registers cannot be written by encoded transfers.
3. All interaction with external devices (and system logic like MMU) is done via MMIO

[^1:] While this approach looks clean and orthogonal, it complicates handling of immediates. It looks like we need at least 2 registers hardcoded to values 0 and 1 to make coding realistic, but creating other constants may require several instructions. Another alternative is to treat register index in one of the pairs as small immediate. It may be handy to use it to select ALU operation (otherwise, we need several units with hardcoded functions) or use it as PC offset to load big constants from instruction memory.

## FEIS32

1. Registers and address bus are 32 bits wide
2. There are 16 registers
3. Instruction is 32 bit and contains 4 src/dst pairs

## Communication with external devices

1. Last addressable word contains a number of available devices
2. Immediately below it there are pairs of device id/device address


