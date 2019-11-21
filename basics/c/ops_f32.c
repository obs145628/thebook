typedef float f32;

f32 f32_beq(f32 x, f32 y)
{
  return x == y;
}

f32 f32_bne(f32 x, f32 y)
{
  return x != y;
}

f32 f32_lt(f32 x, f32 y)
{
  return x < y;
}

f32 f32_le(f32 x, f32 y)
{
  return x <= y;
}

f32 f32_gt(f32 x, f32 y)
{
  return x > y;
}

f32 f32_ge(f32 x, f32 y)
{
  return x >= y;
}

f32 f32_add(f32 x, f32 y)
{
  return x + y;
}

f32 f32_sub(f32 x, f32 y)
{
  return x - y;
}

f32 f32_mul(f32 x, f32 y)
{
  return x * y;
}

f32 f32_div(f32 x, f32 y)
{
  return x / y;
}

f32 f32_not(f32 x)
{
  return !x;
}

f32 f32_pos(f32 x)
{
  return +x;
}

f32 f32_neg(f32 x)
{
  return -x;
}

f32 f32_princ(f32 x)
{
  return ++x;
}

f32 f32_prdec(f32 x)
{
  return --x;
}

f32 f32_poinc(f32 x)
{
  return x++;
}

f32 f32_podec(f32 x)
{
  return x--;
}
