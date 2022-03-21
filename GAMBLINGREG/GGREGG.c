#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "GGREGG.h"

void fillDogs(dogs *d1, dogs *d2, dogs *d3, dogs *d4, dogs *d5, dogs *d6, dogs *d7, dogs *d8, dogs *d9);
void gamble(int *wallet, int *win, int *loss);
void decider(dogs *d, int *wallet, int *wage, int *win, int *loss);
void banking(int *b, int *w);

int main() {
  int bank, wallet = 100, win = 0, loss = 0;
  char choice;

  do { //Intitial menu
  printf("Welcome to Gambling Greg!\n");
  printf("You have $%d\n", wallet);
  printf("What would you like to do?\n");
  printf("[G]amble\n[B]anking\n[R]esults\n[L]eave the dog track\n");
  printf("Enter choice here: ");
  scanf(" %c", &choice);

  switch (choice)
  {
  case 'g':
  case 'G':
    gamble(&wallet, &win, &loss);
    break;
  case 'b':
  case 'B':
    banking(&bank, &wallet);
    break;
  case 'r':
  case 'R':
    printf("You have won %d times!\n", win);
    printf("You have lost %d times...\n", loss);
    break;
  case 'l':
  case 'L':
    printf("Thanks for playing Gambling Greg!\n");
    printf("Goodbye...");
    return 0;
  default:
    printf("Invalid entry\n");
    break;
  }
 } while (choice != 'l' || choice != 'L');
}

void gamble(int *wallet, int *win, int *loss) {
  dogs dog1, dog2, dog3, dog4, dog5, dog6, dog7, dog8, dog9;
  int choice, wage;
  fillDogs(&dog1, &dog2, &dog3, &dog4, &dog5, &dog6, &dog7, &dog8, &dog9);
  printf("Enter a wager: \n");
  scanf("%d", &wage);
  if (wage > *wallet) {
    printf("Cannot wage what you do not have!\n");
    return;
  }
  printf("Choose a dog:\n");
  printf("1. %s Payout: %d to 1 Odds: %d%\n", dog1.name, dog1.payout, dog1.odds);
  printf("2. %s Payout: %d to 1 Odds: %d%\n", dog2.name, dog2.payout, dog2.odds);
  printf("3. %s Payout: %d to 1 Odds: %d%\n", dog3.name, dog3.payout, dog3.odds);
  printf("4. %s Payout: %d to 1 Odds: %d%\n", dog4.name, dog4.payout, dog4.odds);
  printf("5. %s Payout: %d to 1 Odds: %d%\n", dog5.name, dog5.payout, dog5.odds);
  printf("6. %s Payout: %d to 1 Odds: %d%\n", dog6.name, dog6.payout, dog6.odds);
  printf("7. %s Payout: %d to 1 Odds: %d%\n", dog7.name, dog7.payout, dog7.odds);
  printf("8. %s Payout: %d to 1 Odds: %d%\n", dog8.name, dog8.payout, dog8.odds);
  printf("9. %s Payout: %d to 1 Odds: %d%\n", dog9.name, dog9.payout, dog9.odds);
  printf("Enter a number 1 - 9: ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    *wallet = *wallet - wage;
    decider(&dog1, wallet, &wage, win, loss);//Each dog getting their own "sim" for a race
    break;
  case 2:
    *wallet = *wallet - wage;
    decider(&dog2, wallet, &wage, win, loss);
    break;
  case 3:
    *wallet = *wallet - wage;
    decider(&dog3, wallet, &wage, win, loss);
    break;
  case 4:
    *wallet = *wallet - wage;
    decider(&dog4, wallet, &wage, win, loss);
    break;
  case 5:
    *wallet = *wallet - wage;
    decider(&dog5, wallet, &wage, win, loss);
    break;
  case 6:
    *wallet = *wallet - wage;
    decider(&dog6, wallet, &wage, win, loss);
    break;
  case 7:
    *wallet = *wallet - wage;
    decider(&dog7, wallet, &wage, win, loss);
    break;
  case 8:
    *wallet = *wallet - wage;
    decider(&dog8, wallet, &wage, win, loss);
    break;
  case 9:
    *wallet = *wallet - wage;
    decider(&dog9, wallet, &wage, win, loss);
    break;
  default:
    printf("Invalid entry\n");
    printf("Please try again!\n");
    break;
  }
}

void fillDogs(dogs *d1, dogs *d2, dogs *d3, dogs *d4, dogs *d5, dogs *d6, dogs *d7, dogs *d8, dogs *d9) {

  strcpy(d1->name, "Rocco");//Creating dogs
  d1->payout = 2;
  d1->odds = 40;

  strcpy(d2->name, "Ginger");
  d2->payout = 5;
  d2->odds = 10;

  strcpy(d3->name, "Bobo");
  d3->payout = 10;
  d3->odds = 8;

  strcpy(d4->name, "Jack");
  d4->payout = 15;
  d4->odds = 6;

  strcpy(d5->name, "Junior");
  d5->payout = 50;
  d5->odds = 1;

  strcpy(d6->name, "Sammy");
  d6->payout = 20;
  d6->odds = 4;

  strcpy(d7->name, "Emma");
  d7->payout = 10;
  d7->odds = 8;

  strcpy(d8->name, "Poli");
  d8->payout = 5;
  d8->odds = 10;

  strcpy(d9->name, "Whirl");
  d9->payout = 3;
  d9->odds = 13;
}

void decider(dogs *d, int *wallet, int *wage, int *win, int *loss) {// Deciding if you win or lose
  srand(time(NULL));
  int random = rand() % 100 / 1;//Creating a more "true" random
  if (d->odds > random) {
    printf("WINNER!\n");
    *wallet += (d->payout * *wage) + *wage;// Calcualitng payout
    (*win)++;
  }
  else {
    printf("LOSER! HAHAHA\n");
    (*loss)++;
  }
}

void banking(int *bank, int *wallet) {// Banking system
  int choice, depAmount, witAmount;
  printf("Welcome to GG banking.\n");
  printf("What would you like to do?\n");
  printf("1. Deposit\n2. Withdrawl\nEnter choice here:");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    printf("\nEnter deposit amount: ");
    scanf("%d", &depAmount);
    if (depAmount > *wallet) {
      printf("Nice try, you don't have the funds!\n");
      break;
    }
    else {
    *wallet -= depAmount;
    *bank += depAmount;
    break;
    }

  case 2:
    printf("Enter withdrawl amount: ");
    scanf("%d", &witAmount);
    if (witAmount > *bank) {
      printf("Cannot withdraw funds you do not have!\n");
      break;
    }
    else {
    *bank -= witAmount;
    *wallet += witAmount;
    break;
    }

  default:
    printf("Invalid entry\n");
    break;
  }
}