#include <stdint.h>

typedef int8_t i8;

i8 i8_bor(i8 x, i8 y)
{
  return x | y;
}

i8 i8_bxor(i8 x, i8 y)
{
  return x ^ y;
}

i8 i8_band(i8 x, i8 y)
{
  return x & y;
}

i8 i8_beq(i8 x, i8 y)
{
  return x == y;
}

i8 i8_bne(i8 x, i8 y)
{
  return x != y;
}

i8 i8_lt(i8 x, i8 y)
{
  return x < y;
}

i8 i8_le(i8 x, i8 y)
{
  return x <= y;
}

i8 i8_gt(i8 x, i8 y)
{
  return x > y;
}

i8 i8_ge(i8 x, i8 y)
{
  return x >= y;
}

i8 i8_bls(i8 x, i8 y)
{
  return x << y;
}

i8 i8_brs(i8 x, i8 y)
{
  return x >> y;
}

i8 i8_add(i8 x, i8 y)
{
  return x + y;
}

i8 i8_sub(i8 x, i8 y)
{
  return x - y;
}

i8 i8_mul(i8 x, i8 y)
{
  return x * y;
}

i8 i8_div(i8 x, i8 y)
{
  return x / y;
}

i8 i8_mod(i8 x, i8 y)
{
  return x % y;
}

i8 i8_not(i8 x)
{
  return !x;
}

i8 i8_bnot(i8 x)
{
  return ~x;
}

i8 i8_pos(i8 x)
{
  return +x;
}

i8 i8_neg(i8 x)
{
  return -x;
}

i8 i8_princ(i8 x)
{
  return ++x;
}

i8 i8_prdec(i8 x)
{
  return --x;
}

i8 i8_poinc(i8 x)
{
  return x++;
}

i8 i8_podec(i8 x)
{
  return x--;
}
