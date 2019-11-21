
void foo()
{
  
}

void x1(int a1, int a2, int a3)
{
  foo();
}

void x2(int a1, int a2)
{
  foo();
  foo();
}


int decvars()
{
  int a1 = 4;
  int a2 = 7;
  return a2;
}

void decrets()
{
  int rr = decvars();
}


int fn3(int x, int y, int z)
{
  int r = x;
  r = y;
  r = z;
  return r;
}

void call3()
{
  int n = 22;
  int p = 8;
  int l = fn3(n, 5, n);
  int l2 = l;
  int l3 = 6;
}


int fn10(int a0, int a1, int a2, int a3, int a4, int a5, int a6,
	 int a7, int a8, int a9)
{
  int res;
  res = a0;
  res = a1;
  res = a2;
  res = a3;
  res = a4;
  res = a5;
  res = a6;
  res = a7;
  res = a8;
  res = a9;
  return res;
}

void call10()
{
  int x = 17;
  int y = 18;
  int z = 23;
  int l = fn10(x, y, z, 1, x, y, z, 2, y, z);
}
