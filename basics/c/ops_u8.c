#include <stdint.h>

typedef uint8_t u8;

u8 u8_bor(u8 x, u8 y)
{
  return x | y;
}

u8 u8_bxor(u8 x, u8 y)
{
  return x ^ y;
}

u8 u8_band(u8 x, u8 y)
{
  return x & y;
}

u8 u8_beq(u8 x, u8 y)
{
  return x == y;
}

u8 u8_bne(u8 x, u8 y)
{
  return x != y;
}

u8 u8_lt(u8 x, u8 y)
{
  return x < y;
}

u8 u8_le(u8 x, u8 y)
{
  return x <= y;
}

u8 u8_gt(u8 x, u8 y)
{
  return x > y;
}

u8 u8_ge(u8 x, u8 y)
{
  return x >= y;
}

u8 u8_bls(u8 x, u8 y)
{
  return x << y;
}

u8 u8_brs(u8 x, u8 y)
{
  return x >> y;
}

u8 u8_add(u8 x, u8 y)
{
  return x + y;
}

u8 u8_sub(u8 x, u8 y)
{
  return x - y;
}

u8 u8_mul(u8 x, u8 y)
{
  return x * y;
}

u8 u8_div(u8 x, u8 y)
{
  return x / y;
}

u8 u8_mod(u8 x, u8 y)
{
  return x % y;
}

u8 u8_not(u8 x)
{
  return !x;
}

u8 u8_bnot(u8 x)
{
  return ~x;
}

u8 u8_pos(u8 x)
{
  return +x;
}

u8 u8_neg(u8 x)
{
  return -x;
}

u8 u8_princ(u8 x)
{
  return ++x;
}

u8 u8_prdec(u8 x)
{
  return --x;
}

u8 u8_poinc(u8 x)
{
  return x++;
}

u8 u8_podec(u8 x)
{
  return x--;
}
