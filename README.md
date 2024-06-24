# WCH_V307_RISC-V
Bare metal programming on WCH RISC-V MCU CH32V307VCT6 board (CH32V307V-EVT-R1)

<p align="center">
    <a href="https://github.com/Embedded-System-Lovers/WCH_V307_RISC-V/actions">
        <img src="https://github.com/Embedded-System-Lovers/WCH_V307_RISC-V/actions/workflows/WCH_V307_RISC-V.yml/badge.svg" alt="Build Status"></a>
    <a href="https://github.com/Embedded-System-Lovers/WCH_V307_RISC-V/blob/master/LICENSE">
        <img src="https://img.shields.io/badge/license-Unlicense-blue.svg" alt="Unlicense"></a>
</p>

This repository implements an entirely manually-written, pure
_bare_ _metal_ Blinky Project for the SiFive
RISC-V MCU CH32V307VCT6 board  (CH32V307V-EVT-R1).

Features include:
  - CPU, power, chip, clock and PLL initialization,
  - timebase derived from the `R32_STK` timer,
  - blinky LED show with adjustable frequency,
  - implementation in C99 with absolute minimal use of assembly.

Clear and easy-to-understand build systems based on either
GNUmake or CMake complete this fun and educational project.

This repository provides keen insight on starting up
a _bare_ _metal_ SiFive RISC-V controller. It emphasizes
simplicity and independence from monolithic toolchains
through its lightweight, self-written implementation.

## Details on the Application

The application boots from a tiny startup code in the boot ROM.

Following low-level chip initialization, the program jumps to
the `main()` subroutine. Here the timer interrupt is setup
for LED blinky.

The adjustable LED-phase (its half-period) can be tuned
to provide a rudimentary, visible blinky LED show.
The timebase for blinky is based on the `R32_STK` timer
with an interrupt handler once per second.

Blinky running on the target is shown in the image below.
A wire is required connecting port pins `PC0` and `LED1`
in order to observe the blinky toggle. See the orange wire
in the picture.

![](./images/wch_v307.jpg)

## Building the Application

Build on `*nix*` is easy using `gcc-riscv32-unknown-elf`

Both classic GNUmake as well as CMake can be used to build the Application:

```sh
cd WCH_V307_RISC-V/Build
```
### GNUmake

```sh
./Rebuild.sh
```

### CMake
```sh
mkdir Output && cd Output
cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchain-unix.cmake .. && make
```

The build results including ELF-file, HEX-mask, MAP-file
and assembly list file are created in the `Output` directory.

If `gcc-riscv32-unknown-elf` is not installed, it can easily
be obtained from [embecosm](https://www.embecosm.com/resources/tool-chain-downloads/#riscv-stable).
If necessary, add the path of the RISC-V GCC tools' bin folder to
`$PATH` in the usual `*nix` way.

## Continuous Integration

CI runs on pushes and pull-requests with simple
build(s) including result verification on `ubuntu-latest`
and `macos-latest` using GitHub Actions.

## Licensing

  - The source and build code written for this repo are licensed under [_The_ _Unlicense_](./LICENSE).
  - The system-register file [`riscv-csr.h`](https://github.com/Embedded-System-Lovers/RED-V_SiFive_RISC-V_FE310_SoC/blob/master/Code/Mcal/riscv-csr.h), originally from [five-embedded](https://five-embeddev.com), is also licenced under [_The_ _Unlicense_](./LICENSE).
