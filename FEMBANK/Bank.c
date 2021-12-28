#include <stdio.h>

int main() {
  int iSelection = 0;
  float fTransAmount = 0.0;
  float fBalance = 721.0;

  printf("\nWelcome to Femboi Bank of America ^_^\n");
  printf("\n1. Would you like to deposit?\n");
  printf("\n2. or withdraw?\n\v");
  scanf("%d", &iSelection);

  if(iSelection == 1) {
    printf("\nHow much would you like to deposit?\n");
    scanf("%f", &fTransAmount);
    printf("\nThanks for your deposit! Your balance is %f\n", fBalance + fTransAmount);
  }
  if(iSelection == 2) {
    printf("\nHow much would you like to withdraw?\n");
    scanf("%f", &fTransAmount);
    if(fTransAmount>fBalance) 
      printf("\nSorry! Your too broke ^_^");
      else
      printf("\nYour new balance is %f\n", fBalance - fTransAmount);
  }
  return 0;
}