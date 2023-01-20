@echo off

start /B openocd -f wch-riscv.cfg

riscv-none-embed-gdb -x ./../Tools/GDB-Config/gdb.cfg ./../Output/BareMetal_WCH_V307_RISC-V.elf

trap "taskkill /F /IM riscv-none-embed-gdb.exe" EXIT
