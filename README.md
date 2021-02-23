libfpgasoc (Library to control FPGA fabric by using drvfpgasoc)
===============================================================

Overview
--------
This is a library to use FPGA fabric of FPGA SoC (e.g. Cyclone V SoC) by using drvfpgasoc (Linux kernel module to access FPGA fabric).

How to build
------------
```sh
$ mkdir build
$ cd build
$ cmake .. -DCMAKE_INSTALL_PREFIX=<Path to install>
$ make
```

How to install
--------------
```sh
$ make install
```

Requirement
-----------
* cmake
* make
* drvfpgasoc

