#include <stdint.h>

typedef uint32_t u32;

u32 u32_bor(u32 x, u32 y)
{
  return x | y;
}

u32 u32_bxor(u32 x, u32 y)
{
  return x ^ y;
}

u32 u32_band(u32 x, u32 y)
{
  return x & y;
}

u32 u32_beq(u32 x, u32 y)
{
  return x == y;
}

u32 u32_bne(u32 x, u32 y)
{
  return x != y;
}

u32 u32_lt(u32 x, u32 y)
{
  return x < y;
}

u32 u32_le(u32 x, u32 y)
{
  return x <= y;
}

u32 u32_gt(u32 x, u32 y)
{
  return x > y;
}

u32 u32_ge(u32 x, u32 y)
{
  return x >= y;
}

u32 u32_bls(u32 x, u32 y)
{
  return x << y;
}

u32 u32_brs(u32 x, u32 y)
{
  return x >> y;
}

u32 u32_add(u32 x, u32 y)
{
  return x + y;
}

u32 u32_sub(u32 x, u32 y)
{
  return x - y;
}

u32 u32_mul(u32 x, u32 y)
{
  return x * y;
}

u32 u32_div(u32 x, u32 y)
{
  return x / y;
}

u32 u32_mod(u32 x, u32 y)
{
  return x % y;
}

u32 u32_not(u32 x)
{
  return !x;
}

u32 u32_bnot(u32 x)
{
  return ~x;
}

u32 u32_pos(u32 x)
{
  return +x;
}

u32 u32_neg(u32 x)
{
  return -x;
}

u32 u32_princ(u32 x)
{
  return ++x;
}

u32 u32_prdec(u32 x)
{
  return --x;
}

u32 u32_poinc(u32 x)
{
  return x++;
}

u32 u32_podec(u32 x)
{
  return x--;
}
