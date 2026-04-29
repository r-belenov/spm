# Fully Explicit Instruction Set

## Rationale

FEIS is extremely simple ISA family inspired by VLIW without any practical application in mind, just as a learning exercise. Specific FEIS-based ISA must specify available registers, execution units and how parts of instruction determine connection of registers to execution unit pins. It is supposed that one of the registers serves as instruction pointer (probably connected to the input and output of dedicated adder).

## Main ideas

1. Instruction explicitly controls multiplexers connecting registers with input and output pins of execution units
2. Some pins may be hardwared (e.g. program counter can be pinned to input and output of dedicated adder, another input determines offset to the next instruction), for others there are specific bits in in the instruction determining the registers to connect to.
3. Some bits of the instruction may be directly connected to the input of execution unit (e.g. to determine ALU operation).
4. All interaction with external devices (and system logic like MMU) is done via MMIO
5. Last addressable word contains a number of available devices
6. Immediately below it there are pairs of device id/device address

## FEIS32

1. Registers and address bus are 32 bits wide
2. r0 is 1 constant (stores ignored), r1 is pc (program counter)
3. Memory is word addressable
4. There are 16 registers (including program counter and special registers holding constant values)
5. Instruction is 32 bit and includes the following
  - src1 first source register for ALU
  - src2 second source register for ALU
  - dst destinations register for ALU
  - addr register providing address to load/store unit
  - dat register with data for load/store (load destination or store source)
  - off register providing PC increment ( added to r1 by dedicated adder)
  - op ALU operation (4 bits)
  - st bit controlling load/store (store if set)
  - skip if set, next instruction word is nop; otherwise, obtained from data bus (memory or dat depending on st bit)
6. ALU operations:
  - ADD
  - SUB
  - OR
  - XOR
  - AND
  - NAND (inverted AND)
  - SLL
  - SRL
  - SRA
  - CMPEQ
  - CMPLT
  - CMPLE
7. Comments
  - Normal instruction flow happens when addr == 1, off == r0, st == 0, skip == 0
  - CMP* set dst to 0 or all 1s (condional branch pattern is CMP rX, rA, rB; AND rDST, rDST, rX; ADD rDST, rDST, r0; use rDST as off in next instruction)
  - Data loads/stores should set skip to 1; addr == 1 can be used to read immediate following the instruction
