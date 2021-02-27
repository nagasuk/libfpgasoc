libfpgasoc (Library to control FPGA fabric by using drvfpgasoc)
===============================================================

Overview
--------
This is a library to use FPGA fabric of FPGA SoC (e.g. Cyclone V SoC) by using drvfpgasoc (Linux kernel module to access FPGA fabric).

How to build
------------
```sh
$ cmake -S . -B build
$ cmake --build build
```

How to install
--------------
```sh
$ cmake --install build --prefix <Path to install>
```

Requirement
-----------
* cmake
* make
* drvfpgasoc

