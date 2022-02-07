/* Testing Code */

#include <limits.h>
#include <math.h>

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* bit manipulation */
int test_func1(int x) {
  return x == 0;
}
int test_func2(int x, int y)
{
  return ~(x|y);
}
int test_func3(int x, int y)
{
  return x&~y;
}
int test_func4(int x) {
  int i = 0;
  int results = 0;
  for (i = 0; i < 32; i++) {
    int ith_bit = ( (x >> i) & 0x1 );
    if (i < 16) {
      ith_bit = ith_bit << (i + 16);
    } else {
      ith_bit = ith_bit << (i - 16);
    }
    results = results | ith_bit;
  }
  return results;
}
int test_func5(int x)
{
  return (x & 0x1) ? -1 : 0;
}
int test_func6(int x) {
  int i;
  for (i = 0; i < 32; i+=2)
      if ((x & (1<<i)) == 0)
   return 0;
  return 1;
}
int test_func7(int x, int n) {
  unsigned u = (unsigned) x;
  unsigned shifted = u >> n;
  return (int) shifted;
}
/* 2's complement */
int test_func8(void) {
  return 0x80000000;
}
int test_func9(int x) {
    return x == 0x7FFFFFFF;
}
int test_func10(int x) {
  return -x;
}
int test_func11(int x, int y)
{
    long long lsum = (long long) x + y;
    return lsum == (int) lsum;
}
int test_func12(int x, int y)
{
  return x > y;
}
int test_func13(int x, int y)
{
  if (x > 0 && y > 0 && x+y < 0)
    return (0x7FFFFFFF);
  if (x < 0 && y < 0 && x+y >= 0)
    return (0x80000000);
  return x + y;
}
