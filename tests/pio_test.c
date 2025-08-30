/* pio.h - v0.1 - public domain data structures - nickscha 2025

A C89 standard compliant, single header, nostdlib (no C Standard Library) Platform IO Provider (PIO).

This Test class defines cases to verify that we don't break the excepted behaviours in the future upon changes.

LICENSE

  Placed in the public domain and also MIT licensed.
  See end of file for detailed license information.

*/
#include "../pio.h" /* Platform IO Provider     */
#include "test.h"   /* Simple Testing framework */

void pio_test_read_write(void)
{
#define BUFFER_CAPACITY 1024
  unsigned char buffer[BUFFER_CAPACITY];
  unsigned long buffer_size = 0;

  /* Write a new file */
  buffer[0] = 'H';
  buffer[1] = 'e';
  buffer[2] = 'l';
  buffer[3] = 'l';
  buffer[4] = 'o';
  buffer[5] = ' ';
  buffer[6] = 'P';
  buffer[7] = 'I';
  buffer[8] = 'O';
  buffer[9] = '!';
  buffer_size = 10;
  assert(pio_write("testfile.txt", buffer, buffer_size));
  assert(pio_read("testfile.txt", buffer, BUFFER_CAPACITY, &buffer_size));
  assert(pio_file_size("testfile.txt") == buffer_size);
  assert(pio_write("outfile.txt", buffer, buffer_size));
  assert(pio_read("outfile.txt", buffer, BUFFER_CAPACITY, &buffer_size));
  assert(pio_file_size("outfile.txt") == pio_file_size("testfile.txt"));

  assert(buffer[0] == 'H');
  assert(buffer[1] == 'e');
  assert(buffer[2] == 'l');
  assert(buffer[3] == 'l');
  assert(buffer[4] == 'o');
  assert(buffer[5] == ' ');
  assert(buffer[6] == 'P');
  assert(buffer[7] == 'I');
  assert(buffer[8] == 'O');
  assert(buffer[buffer_size - 1] == '!');
}

int main(void)
{
  pio_print("Starting testsuite\n");

  pio_test_read_write();

  pio_print("Stopping testsuite\n");

  return 0;
}

/*
   -----------------------------------------------------------------------------
   This software is available under 2 licenses -- choose whichever you prefer.
   ------------------------------------------------------------------------------
   ALTERNATIVE A - MIT License
   Copyright (c) 2025 nickscha
   Permission is hereby granted, free of charge, to any person obtaining a copy of
   this software and associated documentation files (the "Software"), to deal in
   the Software without restriction, including without limitation the rights to
   use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
   of the Software, and to permit persons to whom the Software is furnished to do
   so, subject to the following conditions:
   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.
   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
   ------------------------------------------------------------------------------
   ALTERNATIVE B - Public Domain (www.unlicense.org)
   This is free and unencumbered software released into the public domain.
   Anyone is free to copy, modify, publish, use, compile, sell, or distribute this
   software, either in source code form or as a compiled binary, for any purpose,
   commercial or non-commercial, and by any means.
   In jurisdictions that recognize copyright laws, the author or authors of this
   software dedicate any and all copyright interest in the software to the public
   domain. We make this dedication for the benefit of the public at large and to
   the detriment of our heirs and successors. We intend this dedication to be an
   overt act of relinquishment in perpetuity of all present and future rights to
   this software under copyright law.
   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
   WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
   ------------------------------------------------------------------------------
*/
