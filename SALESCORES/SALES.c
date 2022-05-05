//Zakary Smith 03/18/2021
//Program demosntrating mutable structs passed through functions
//Allows you to enter and calculate a salespersons income and sales as well as view their total income and sales
//Scales progressively with the amount of sales no matter how many times you switch between people

#include <stdio.h>
#include <stdlib.h>
#include "SALES.h"

void salesTime(seller *salesPerson);

int main() {
  seller eris = {0}, drifter = {0}, elsie = {0};
  int choice;
  do {
  printf("Choose sales person:\n");
  printf("1. Eris\n2. Drifter\n3. Elsie\n4. Quit\n");
  printf("Enter option here: ");
  scanf(" %d", &choice);

  switch (choice) {
  case 1:
    salesTime(&eris);
    break;
  case 2:
    salesTime(&drifter);
    break;
  case 3:
    salesTime(&elsie);
    break;
  case 4:
    return 0;
  default: //Used as user error protection since there is not a lot of ways they can do bad things here
    printf("Invalid option please try again.\n");
    break;
  }
} while (choice != 4);
}
void salesTime(seller *salesPerson) {
  int choice, sale, cash = 0;

  do {
  printf("What woud you like to do:\n");
  printf("1. Record new sale\n");
  printf("2. Show total income and sales\n");
  printf("3. Quit\n");
  printf("Enter option here: ");
  scanf(" %d", &choice);

  switch (choice) {
  case 1:
    printf("Enter sales amount: ");
    scanf(" %d", &sale);
    salesPerson->sales += sale;

    for (int i = 0; i < sale; i++) { //Determining 
      if (i <= 5 && i > 0 || salesPerson->sales <= 5 && salesPerson->sales > 0) {
        cash += 5;
      }
      else if (i > 5 && i <= 10 || salesPerson->sales > 5 && salesPerson->sales <= 10) {
        cash += 10;
      }
      else if (i > 10 && i <= 510 || salesPerson->sales > 10 && salesPerson->sales <= 510) {
        cash += 25;
      }
      else if (i > 510 || salesPerson->sales > 510) {
        cash += 35;
      }
    }
    salesPerson->income = cash;
    printf("%d\n", salesPerson->income);
    break;
  case 2: //Show income and total sales
    printf("%d\n", salesPerson->sales);
    printf("%d\n", salesPerson->income);
    break;
  case 3:
    return;
  default: //User error case pt. 2
    printf("Invalid option please try again.\n");
    break;
  }
  } while (choice != 3);
}