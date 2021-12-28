#include <stdio.h>
#include <stdlib.h>
int main (void) {
  int smol, larg = 0, avrg = 0, elem = 0, elems = 0;
  do {
  printf ("\nEnter some numbahs: \n");
  scanf ("%d", &elem);
	if (elems == 0 || (elem < smol && elem > 0))
	{
     smol = elem;
  }
  if (elem > larg)
	{
     larg = elem;
  }
  if (elem > 0)
	{
     avrg += elem;
     ++elems;
  }
}
while (elem != -1);
avrg = avrg / elems;
printf ("\nYou entered %d numbahs", elems);
printf ("\nYour average is: %d", avrg);
printf ("\nSmollest numbah is: %d", smol);
printf ("\nLargest numbah is: %d\n", larg);
system ("pause");
}