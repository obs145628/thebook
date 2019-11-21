#include <stdint.h>

typedef int32_t i32;

i32 i32_bor(i32 x, i32 y)
{
  return x | y;
}

i32 i32_bxor(i32 x, i32 y)
{
  return x ^ y;
}

i32 i32_band(i32 x, i32 y)
{
  return x & y;
}

i32 i32_beq(i32 x, i32 y)
{
  return x == y;
}

i32 i32_bne(i32 x, i32 y)
{
  return x != y;
}

i32 i32_lt(i32 x, i32 y)
{
  return x < y;
}

i32 i32_le(i32 x, i32 y)
{
  return x <= y;
}

i32 i32_gt(i32 x, i32 y)
{
  return x > y;
}

i32 i32_ge(i32 x, i32 y)
{
  return x >= y;
}

i32 i32_bls(i32 x, i32 y)
{
  return x << y;
}

i32 i32_brs(i32 x, i32 y)
{
  return x >> y;
}

i32 i32_add(i32 x, i32 y)
{
  return x + y;
}

i32 i32_sub(i32 x, i32 y)
{
  return x - y;
}

i32 i32_mul(i32 x, i32 y)
{
  return x * y;
}

i32 i32_div(i32 x, i32 y)
{
  return x / y;
}

i32 i32_mod(i32 x, i32 y)
{
  return x % y;
}

i32 i32_not(i32 x)
{
  return !x;
}

i32 i32_bnot(i32 x)
{
  return ~x;
}

i32 i32_pos(i32 x)
{
  return +x;
}

i32 i32_neg(i32 x)
{
  return -x;
}

i32 i32_princ(i32 x)
{
  return ++x;
}

i32 i32_prdec(i32 x)
{
  return --x;
}

i32 i32_poinc(i32 x)
{
  return x++;
}

i32 i32_podec(i32 x)
{
  return x--;
}
