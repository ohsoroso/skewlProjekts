#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int num1, num2, num3, num4, num5, n, smol, larg, sum, avrg;

  printf("Welcome !\nPlease enter FIVE numbers.\n"); //Choose and enter your five numbers
    scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);
    sum = num1 + num2 + num3 + num4 + num5; //Calculate sum
    avrg = sum / 5; //Calculate average
    if (num1 < num2 && num1 < num3 && num1 < num4 && num1 < num5)
    {
      smol = num1;
    }
      else if (num2 < num3 && num2 < num4 && num2 < num5)
      {
        smol = num2;
      }
      else if (num3 < num4 && num3 < num5)
      {
        smol = num3;
      }
      else if (num4 < num5)
      {
        smol = num4;
      }
      else
      {
        smol = num5;                   //Calculate smallest number
      }

    if (num1 > num2 && num1 > num3 && num1 > num4 && num1 > num5)
    {
      larg = num1;
    }
      else if (num2 > num3 && num2 > num4 && num2 > num5)
      {
        larg = num2;
      }
      else if (num3 > num4 && num3 > num5)
      {
        larg = num3;
      }
      else if (num4 > num5)
      {
        larg = num4;
      }
      else
      {
        larg = num5;                    //Calculate largest number
      }
    
  printf("Thank you!\nWhat would you like to know about these numbers ?");
    printf("\n\t1. Smallest Number\n\t2. Largest Number\n\t3. Sum of Numbers\n\t4. Average of Numbers\n");
    scanf("%d", &n); //Present and select options
    
  if (n > 4)
    {
      printf("\nThat is not an option silly billy hilichurl !");
    }
    
  switch(n) { //The menu itself
      case 1: printf("\nThe smallest number was: %d\n", smol);
            break;
      case 2: printf("\nThe largest number was: %d\n", larg);
            break;
      case 3: printf("\nThe sum of all the numbers is: %d\n", sum);
            break;
      case 4: printf("\n The average of all the numbers is: %lf\n", (double) avrg);
            break;
  }
  
  system("pause");
}