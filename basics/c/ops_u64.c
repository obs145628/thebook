#include <stdint.h>

typedef uint64_t u64;

u64 u64_bor(u64 x, u64 y)
{
  return x | y;
}

u64 u64_bxor(u64 x, u64 y)
{
  return x ^ y;
}

u64 u64_band(u64 x, u64 y)
{
  return x & y;
}

u64 u64_beq(u64 x, u64 y)
{
  return x == y;
}

u64 u64_bne(u64 x, u64 y)
{
  return x != y;
}

u64 u64_lt(u64 x, u64 y)
{
  return x < y;
}

u64 u64_le(u64 x, u64 y)
{
  return x <= y;
}

u64 u64_gt(u64 x, u64 y)
{
  return x > y;
}

u64 u64_ge(u64 x, u64 y)
{
  return x >= y;
}

u64 u64_bls(u64 x, u64 y)
{
  return x << y;
}

u64 u64_brs(u64 x, u64 y)
{
  return x >> y;
}

u64 u64_add(u64 x, u64 y)
{
  return x + y;
}

u64 u64_sub(u64 x, u64 y)
{
  return x - y;
}

u64 u64_mul(u64 x, u64 y)
{
  return x * y;
}

u64 u64_div(u64 x, u64 y)
{
  return x / y;
}

u64 u64_mod(u64 x, u64 y)
{
  return x % y;
}

u64 u64_not(u64 x)
{
  return !x;
}

u64 u64_bnot(u64 x)
{
  return ~x;
}

u64 u64_pos(u64 x)
{
  return +x;
}

u64 u64_neg(u64 x)
{
  return -x;
}

u64 u64_princ(u64 x)
{
  return ++x;
}

u64 u64_prdec(u64 x)
{
  return --x;
}

u64 u64_poinc(u64 x)
{
  return x++;
}

u64 u64_podec(u64 x)
{
  return x--;
}
