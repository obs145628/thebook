#include <stdint.h>

typedef int16_t i16;

i16 i16_bor(i16 x, i16 y)
{
  return x | y;
}

i16 i16_bxor(i16 x, i16 y)
{
  return x ^ y;
}

i16 i16_band(i16 x, i16 y)
{
  return x & y;
}

i16 i16_beq(i16 x, i16 y)
{
  return x == y;
}

i16 i16_bne(i16 x, i16 y)
{
  return x != y;
}

i16 i16_lt(i16 x, i16 y)
{
  return x < y;
}

i16 i16_le(i16 x, i16 y)
{
  return x <= y;
}

i16 i16_gt(i16 x, i16 y)
{
  return x > y;
}

i16 i16_ge(i16 x, i16 y)
{
  return x >= y;
}

i16 i16_bls(i16 x, i16 y)
{
  return x << y;
}

i16 i16_brs(i16 x, i16 y)
{
  return x >> y;
}

i16 i16_add(i16 x, i16 y)
{
  return x + y;
}

i16 i16_sub(i16 x, i16 y)
{
  return x - y;
}

i16 i16_mul(i16 x, i16 y)
{
  return x * y;
}

i16 i16_div(i16 x, i16 y)
{
  return x / y;
}

i16 i16_mod(i16 x, i16 y)
{
  return x % y;
}

i16 i16_not(i16 x)
{
  return !x;
}

i16 i16_bnot(i16 x)
{
  return ~x;
}

i16 i16_pos(i16 x)
{
  return +x;
}

i16 i16_neg(i16 x)
{
  return -x;
}

i16 i16_princ(i16 x)
{
  return ++x;
}

i16 i16_prdec(i16 x)
{
  return --x;
}

i16 i16_poinc(i16 x)
{
  return x++;
}

i16 i16_podec(i16 x)
{
  return x--;
}
