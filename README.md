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

If you would like to build it as a SHARED library, please type the following command.

```sh
$ cmake -S . -B build -DLIBFPGASOC_BUILD_SHARED_LIBS=ON
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

License
-------
Please see `LICENSE.md` file for details.

