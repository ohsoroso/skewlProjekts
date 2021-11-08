#include <stdio.h>
#include <stdlib.h>

 int main (){
 int fiver = 0, divington = 0, number = 8, count = 1,
 multiple = 0, sum = 0, odds = 1, counter = 0, summery = 0;
  
 printf ("\nMultiples of 5\n");
 do
    {
      fiver = fiver + 5;
      printf ("\n%i\n", fiver);
    }
 while (fiver < 55);
 
 printf ("\nDivisible by 2 and 7\n");
 do
    {
      divington++;
      if (divington % 7 == 0 && divington % 2 == 0)
	  printf ("\n%i\n", divington);
    }
 while (divington < 200);
 
 printf("\nMultiples of 8 and sum\n");
 do 
    {
      multiple = number * count;    
      count = ++count;
      if (multiple > 100 && multiple < 500)
      {
      sum += multiple;
      printf("\n%i\n", multiple);
      }
    }
 while (multiple < 500);
 printf("\nSum:%i\n",sum);
 
 printf("\nSum of odd numbers:\n");
 do
    {
      odds = odds + 2;    
      if (odds > 20 && odds < 99)
      {
      counter += odds;
      printf("\n%i\n", odds);
      }
    }
 while (odds < 99);
 summery = odds + counter;
 printf("\n%i\n", summery);
 
 system("pause");
}
