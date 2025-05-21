# spm
System Programmer's Minimum

This is a placeholder for the things that, I think, every system programmer should do before applying for a job but I personally didn't try even after 25 years in the industry. Here is a plan

- 1_arch design a CPU architecture
  - 1_doc document of an ISA (and probably some system level)
  - 2_emu software simulator
    - 1_func functional
    - 2_clock clock accurate
  - 3_llvm backend for llvm
- 2_uarch design a microarchitecture
  - 1_sim HDL (SystemVerilog?) impementation that can be simulated (e.g. in Icarus Verilog); should by synthesizable
  - 2_fpga implementation for some FPGA
  - 3_asic
  - 4_llvm scheduling model for llvm
- 3_lang design programming language
  - 1_start interpeter or transpiler
  - 2_comp compiler fo 1_arch
    - 1_scratch implementation without external dependencies
    - 2_llvm frontend for llvm
- 4_os desing operating system
  - 1_doc
  - 2_impl implementation in 3_lang for 1_arch
  
