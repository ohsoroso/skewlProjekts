#include <stdio.h>

int main() {
int numbahWon = 0;
int numbahToo = 0;

int difference = 0;
int product = 0;
int square1 = 0;
int square2 = 0;

printf("\nWelcome!\n");
printf("\nEnter a number: ");
scanf("%d", &numbahWon);

printf("Enter another number: ");
scanf("%d", &numbahToo);

difference = numbahWon - numbahToo;
product = numbahWon * numbahToo;
square1 = numbahWon * numbahWon;
square2 = numbahToo * numbahToo;
printf("The difference is %d ", difference);
printf("The product is %d ", product);
printf("The square of %d is %d ", numbahWon, square1);
printf("The square of %d is %d ",numbahToo, square2);
system("pause");
return 0;
}