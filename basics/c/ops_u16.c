#include <stdint.h>

typedef uint16_t u16;

u16 u16_bor(u16 x, u16 y)
{
  return x | y;
}

u16 u16_bxor(u16 x, u16 y)
{
  return x ^ y;
}

u16 u16_band(u16 x, u16 y)
{
  return x & y;
}

u16 u16_beq(u16 x, u16 y)
{
  return x == y;
}

u16 u16_bne(u16 x, u16 y)
{
  return x != y;
}

u16 u16_lt(u16 x, u16 y)
{
  return x < y;
}

u16 u16_le(u16 x, u16 y)
{
  return x <= y;
}

u16 u16_gt(u16 x, u16 y)
{
  return x > y;
}

u16 u16_ge(u16 x, u16 y)
{
  return x >= y;
}

u16 u16_bls(u16 x, u16 y)
{
  return x << y;
}

u16 u16_brs(u16 x, u16 y)
{
  return x >> y;
}

u16 u16_add(u16 x, u16 y)
{
  return x + y;
}

u16 u16_sub(u16 x, u16 y)
{
  return x - y;
}

u16 u16_mul(u16 x, u16 y)
{
  return x * y;
}

u16 u16_div(u16 x, u16 y)
{
  return x / y;
}

u16 u16_mod(u16 x, u16 y)
{
  return x % y;
}

u16 u16_not(u16 x)
{
  return !x;
}

u16 u16_bnot(u16 x)
{
  return ~x;
}

u16 u16_pos(u16 x)
{
  return +x;
}

u16 u16_neg(u16 x)
{
  return -x;
}

u16 u16_princ(u16 x)
{
  return ++x;
}

u16 u16_prdec(u16 x)
{
  return --x;
}

u16 u16_poinc(u16 x)
{
  return x++;
}

u16 u16_podec(u16 x)
{
  return x--;
}
