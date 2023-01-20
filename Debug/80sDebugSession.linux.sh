#!/bin/bash

openocd -f wch-riscv.cfg > /dev/null 2>&1 &

riscv-none-embed-gdb -x ".\..\Tools\GDB-Config\gdb.cfg" ".\..\Output\BareMetal_WCH_V307_RISC-V.elf"

trap "kill $(pgrep riscv-none-embed-gdb)" EXIT

