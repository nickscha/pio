# pio
A C89 standard compliant, single header, nostdlib (no C Standard Library) Platform IO Provider (PIO).

For more information please look at the "pio.h" file or take a look at the "examples" or "tests" folder.

> [!WARNING]
> THIS PROJECT IS A WORK IN PROGRESS! ANYTHING CAN CHANGE AT ANY MOMENT WITHOUT ANY NOTICE! USE THIS PROJECT AT YOUR OWN RISK!

<p align="center">
  <a href="https://github.com/nickscha/pio/releases">
    <img src="https://img.shields.io/github/v/release/nickscha/pio?style=flat-square&color=blue" alt="Latest Release">
  </a>
  <a href="https://github.com/nickscha/pio/releases">
    <img src="https://img.shields.io/github/downloads/nickscha/pio/total?style=flat-square&color=brightgreen" alt="Downloads">
  </a>
  <a href="https://opensource.org/licenses/MIT">
    <img src="https://img.shields.io/badge/License-MIT-yellow.svg?style=flat-square" alt="License">
  </a>
  <img src="https://img.shields.io/badge/Standard-C89-orange?style=flat-square" alt="C Standard">
  <img src="https://img.shields.io/badge/nolib-nostdlib-lightgrey?style=flat-square" alt="nostdlib">
</p>

<p align="center">
  <b>PIO</b> lets you <b>read/write files, get file sizes, print strings</b> all without relying on the C Standard Library.
</p>

## **Features**
- **C89 compliant** — portable and legacy-friendly  
- **Single-header API** — just include `pio.h`  
- **nostdlib** — no dependency on the C Standard Library  
- **Minimal binary size** — optimized for small executables  
- **Cross-platform** — Windows, Linux, MacOs
- **Strict compilation** — built with aggressive warnings & safety checks

## Quick Start

Download or clone pio.h and include it in your project.

```C
#include "pio.h" /* Platform IO Provider */

int main() {
    /* For simplicity we use a stack */
    /* In real applications you can use pio_file_size and then allocate that amount of memory */
    #define BUFFER_CAPACITY 1024
    unsigned char buffer[BUFFER_CAPACITY];
    unsigned long buffer_size = 0;

    /* Get a file size */
    unsigned long file_size = pio_file_size("testfile.txt");
    (void) file_size;

    /* Print to console */
    if (!pio_print("Hello C89 nostdlib!\n")) {
      return 1;
    }

    /* Read entire file */
    if (!pio_read("testfile.txt", buffer, BUFFER_CAPACITY, &buffer_size)) {
      return 1;
    }

    /* Write entire file */
    if (!pio_write("outfile.txt", buffer, buffer_size)) {
      return 1;
    }

    /* Check if the written file has the same size as the input file */
    if (pio_file_size("outfile.txt") != pio_file_size("testfile.txt")) {
      return 1;
    }

    return 0;
}
```

## Run Example: nostdlib, freestsanding

In this repo you will find the "examples/pio_win32_nostdlib.c" with the corresponding "build.bat" file which
creates an executable only linked to "kernel32" and is not using the C standard library and executes the program afterwards.

## "nostdlib" Motivation & Purpose

nostdlib is a lightweight, minimalistic approach to C development that removes dependencies on the standard library. The motivation behind this project is to provide developers with greater control over their code by eliminating unnecessary overhead, reducing binary size, and enabling deployment in resource-constrained environments.

Many modern development environments rely heavily on the standard library, which, while convenient, introduces unnecessary bloat, security risks, and unpredictable dependencies. nostdlib aims to give developers fine-grained control over memory management, execution flow, and system calls by working directly with the underlying platform.

### Benefits

#### Minimal overhead
By removing the standard library, nostdlib significantly reduces runtime overhead, allowing for faster execution and smaller binary sizes.

#### Increased security
Standard libraries often include unnecessary functions that increase the attack surface of an application. nostdlib mitigates security risks by removing unused and potentially vulnerable components.

#### Reduced binary size
Without linking to the standard library, binaries are smaller, making them ideal for embedded systems, bootloaders, and operating systems where storage is limited.

#### Enhanced performance
Direct control over system calls and memory management leads to performance gains by eliminating abstraction layers imposed by standard libraries.

#### Better portability
By relying only on fundamental system interfaces, nostdlib allows for easier porting across different platforms without worrying about standard library availability.
