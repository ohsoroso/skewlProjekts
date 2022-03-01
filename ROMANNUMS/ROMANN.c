#include <stdio.h>
#include <stdlib.h>

void numToRom(int num);

int main() {
  int num, ans;
  do {
  printf("Enter a number to be converted: ");
  scanf("%d", &num);
  if (num > 1000 || num < 1) { //Check for user error
    printf("Invalid number please try again.");
    printf("Enter a number to be converted: ");
    scanf("%d", &num);
  } 
  else {
    numToRom(num);
  }
  printf("\nEnter another number?\n"); //Let user enter another number
  printf("1. Yes\n2. No\n");
  scanf("%d", &ans);
  } while (ans != 2);
}

void numToRom(int num) { //Parallel arrays to compare numbers with symbols
  int size = 12;
  int nums[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    char *sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 
    while(num>0) //Make sure number is valid
    {
      int split = num/nums[size]; //Divide number by largest number
      num = num%nums[size];
      while(split--)
      {
        printf("%s", sym[size]);
      }
      size--; //Decrement to keep checking lower numbers
    }
}