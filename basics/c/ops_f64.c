typedef double f64;

f64 f64_beq(f64 x, f64 y)
{
  return x == y;
}

f64 f64_bne(f64 x, f64 y)
{
  return x != y;
}

f64 f64_lt(f64 x, f64 y)
{
  return x < y;
}

f64 f64_le(f64 x, f64 y)
{
  return x <= y;
}

f64 f64_gt(f64 x, f64 y)
{
  return x > y;
}

f64 f64_ge(f64 x, f64 y)
{
  return x >= y;
}

f64 f64_add(f64 x, f64 y)
{
  return x + y;
}

f64 f64_sub(f64 x, f64 y)
{
  return x - y;
}

f64 f64_mul(f64 x, f64 y)
{
  return x * y;
}

f64 f64_div(f64 x, f64 y)
{
  return x / y;
}

f64 f64_not(f64 x)
{
  return !x;
}

f64 f64_pos(f64 x)
{
  return +x;
}

f64 f64_neg(f64 x)
{
  return -x;
}

f64 f64_princ(f64 x)
{
  return ++x;
}

f64 f64_prdec(f64 x)
{
  return --x;
}

f64 f64_poinc(f64 x)
{
  return x++;
}

f64 f64_podec(f64 x)
{
  return x--;
}
