#include <stdint.h>

typedef int64_t i64;

i64 i64_bor(i64 x, i64 y)
{
  return x | y;
}

i64 i64_bxor(i64 x, i64 y)
{
  return x ^ y;
}

i64 i64_band(i64 x, i64 y)
{
  return x & y;
}

i64 i64_beq(i64 x, i64 y)
{
  return x == y;
}

i64 i64_bne(i64 x, i64 y)
{
  return x != y;
}

i64 i64_lt(i64 x, i64 y)
{
  return x < y;
}

i64 i64_le(i64 x, i64 y)
{
  return x <= y;
}

i64 i64_gt(i64 x, i64 y)
{
  return x > y;
}

i64 i64_ge(i64 x, i64 y)
{
  return x >= y;
}

i64 i64_bls(i64 x, i64 y)
{
  return x << y;
}

i64 i64_brs(i64 x, i64 y)
{
  return x >> y;
}

i64 i64_add(i64 x, i64 y)
{
  return x + y;
}

i64 i64_sub(i64 x, i64 y)
{
  return x - y;
}

i64 i64_mul(i64 x, i64 y)
{
  return x * y;
}

i64 i64_div(i64 x, i64 y)
{
  return x / y;
}

i64 i64_mod(i64 x, i64 y)
{
  return x % y;
}

i64 i64_not(i64 x)
{
  return !x;
}

i64 i64_bnot(i64 x)
{
  return ~x;
}

i64 i64_pos(i64 x)
{
  return +x;
}

i64 i64_neg(i64 x)
{
  return -x;
}

i64 i64_princ(i64 x)
{
  return ++x;
}

i64 i64_prdec(i64 x)
{
  return --x;
}

i64 i64_poinc(i64 x)
{
  return x++;
}

i64 i64_podec(i64 x)
{
  return x--;
}
