# matrix-multiplier-hls-lab1
# Matrix Multiplier – Vivado HLS (Lab 1)

## Overview
This project implements a hardware-accelerated matrix multiplication algorithm using **Xilinx Vivado HLS**. The goal is to optimize the design through parallelism and custom HLS directives for improved performance on FPGA targets.

> 📘 **Note:** The lab report and project presentation are written in Greek.

## Contents
- `lab1.cpp`: Hardware function `matrix_multiply_hw` with optimization directives.
- `tb_lab1.cpp`: Testbench to verify correctness against a software implementation.
- `report_lab_1.pdf`: Lab report describing implementation, synthesis, and performance results (in Greek).
- `team_2B_lab_1.zip`: Complete Vivado HLS project files.

## How to Run
1. Open **Vivado HLS**.
2. Create a new HLS project and import `lab1.cpp` and `tb_lab1.cpp`.
3. Set `matrix_multiply_hw` as the top-level function.
4. Run:
   - C Simulation
   - C Synthesis
   - C/RTL Co-Simulation
5. Verify the hardware output matches the software result.

## Optimizations Used
- `#pragma HLS ARRAY_PARTITION` to partition arrays and enable parallel access.
- `#pragma HLS UNROLL` to unroll loops for full parallel computation.
- Complete partitioning of A and B matrices across inner loop dimensions.

## Authors
- Dimitrios Orestis Vagenas (10595)
- Angeliki Strataki (10523)
