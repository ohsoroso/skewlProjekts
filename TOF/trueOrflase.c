#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a = 5, b = 4, c = 3, d = 2;
  int arg1 = (a <= b + 1);
  int arg2 = (a < b && c > b);
  int arg3 = (a >= c || d >= 5);
  int arg4 = (! (a > b));
  int arg5 = (b = a && !(d < b));

  if (arg1 == 0)
  {
    printf("FALSE\n");
  }
  else
  {
    printf("TRUE\n");
  }

  if (arg2 == 0)
  {
    printf("FALSE\n");
  }
  else
  {
    printf("TRUE\n");
  }

  if (arg3 == 0)
  {
    printf("FALSE\n");
  }
  else
  {
    printf("TRUE\n");
  }

  if (arg4 == 0)
  {
    printf("FALSE\n");
  }
  else
  {
    printf("TRUE\n");
  }

  if (arg5 == 0)
  {
    printf("FALSE\n");
  }
  else
  {
    printf("TRUE\n");
  }

  system("pause");
}
