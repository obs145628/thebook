#include <stdio.h>


#define NFOUND (-1)


int binsearch(int* arr, int len, int x)
{
  int beg = 0;
  int end = len;

  while (beg < end)
  {
    int mid = (beg + end) / 2;
    if (x < arr[mid])
      end = mid;
    else if (x > arr[mid])
      beg = mid + 1;
    else
      return mid;
  }

  return NFOUND;
}

int main()
{
  int arr[] = {-8, -5, -4, -2, 0, 1, 5, 6, 8, 12, 14, 17, 20};
  int len = sizeof(arr) / sizeof(int);

  for (int i = 0; i < len; ++i)
    printf("%d => %d\n", i, binsearch(arr, len, arr[i]));

  printf("-1 => %d\n", binsearch(arr, len, -15));
  printf("-1 => %d\n", binsearch(arr, len, -7));
  printf("-1 => %d\n", binsearch(arr, len, 3));
  printf("-1 => %d\n", binsearch(arr, len, 16));
  printf("-1 => %d\n", binsearch(arr, len, 26));

  return 0;
}
