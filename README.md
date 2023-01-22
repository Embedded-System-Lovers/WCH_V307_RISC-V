# WCH_V307_RISC-V
Bare metal programming on WCH RISC-V MCU CH32V307VCT6 board (CH32V307V-EVT-R1)

[![Build Status](https://github.com/Embedded-System-Lovers/WCH_V307_RISC-V/actions/workflows/WCH_V307_RISC-V.yml/badge.svg)](https://github.com/Embedded-System-Lovers/WCH_V307_RISC-V/actions)

This repository implements an entirely manually-written, pure
_bare_ _metal_ Blinky Project for the SiFive
RISC-V MCU CH32V307VCT6 board  (CH32V307V-EVT-R1).

Features include:
  - CPU, power, chip, clock and PLL initialization,
  - timebase derived from `mtimer`,
  - blinky LED show with adjustable frequency,
  - implementation in C99 with absolute minimal use of assembly.

A clear and easy-to-understand build system based on GNUmake
completes this fun and educational project.

This repository provides keen insight on starting up
a _bare_ _metal_ SiFive RISC-V controller.

## Details on the Application

The application boots from a tiny startup code in the boot ROM.

Following low-level chip initialization, the program jumps to
the `main()` subroutine. Here the timer interrupt is setup
for LED blinky.

The adjustable LED-phase (its half-period) can be tuned
to provide a rudimentary, visible blinky LED show.
The timebase for blinky is based on the `mtimer`
interrupt handler.

## Building the Application

Build on `*nix*` is easy using an installed `gcc-riscv-none-embed`

Make or CMake can be used to build the Application:

```sh
cd WCH_V307_RISC-V
```
### Make
```sh
cd Build
bash Rebuild.sh
```
### CMake
```sh
mkdir -p Output && cd Output
cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchain-unix.cmake .. && make
```
The build results including ELF-file, HEX-mask, MAP-file
and assembly list file are created in the `Output` directory.

If `gcc-riscv-none-embed` is not installed, it can easily
be obtained [here](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases).
Add the path of the RISC-V GCC tools' bin folder to `$PATH`
in the usual `*nix` way.

## Continuous Integration

CI runs on pushes and pull-requests with simple
at the moment a single build including result verification
runs on `ubuntu-latest` using GitHub Actions.
