#include <stdio.h>
#include <stdlib.h>

//Declare functions
void game_result(int array [] [3]);
void list_scores(int array [] [3]);
void games_won(int array [] [3]);
void scores_sort(int array [] [3]);

int main() {
int game [2] [3], i, j;
char choice;
  //Set menu
  do {
        printf("\n\n************************* \n");
        printf("**      MAIN MENU     *** \n");
        printf("************************* \n\n");
        printf("[A]Enter game result \n");
        printf("[B]Current Record(# of wins and # of losses and # of ties \n");
        printf("[C]Display ALL results from all games WON \n");
        printf("[D]Display ALL results ordered by oponent score from low to high. \n");
        printf("[E]Quit the program \n");
        printf("Enter an option: ");
        scanf(" %c",&choice);
        
        //Set menu options
        switch(choice)
        {
            case 'A': game_result(game);
              break;
            case 'B': list_scores(game);
              break;
            case 'C': games_won(game);
              break;
            case 'D': scores_sort(game);
              break;
            case 'E': printf("Quitting program!\n");
        }
        
    } while (choice != 'E');
    return 0;
}
//Store result for you and your opp
void game_result(int array [] [3]) {
    int i, j;
    printf("Enter team scores: \n");
    for (i = 0; i < 1; i++) {
      for (j = 0; j < 3; j++) {
        scanf("%d", &array [i] [j]);
    }
  }
  printf("Enter opponent scores: \n");
    for (i = 1; i < 2; i++) {
      for (j = 0; j < 3; j++) {
        scanf("%d", &array [i] [j]);
    }
  }
  return;
}
//Find wins, losses, and ties
void list_scores(int array [] [3]) {
    int i, j, win = 0, loss = 0, tie = 0;
    for (j = 0; j < 3; j++) {
    if (array [0] [j] < array [1] [j]) {
        loss++;
    }
    if (array [0] [j] > array [1] [j]) {
        win++;
      }
    if (array [0] [j] == array [1] [j]) {
        tie++;
    }
  }
  printf("Wins: %d\nLosses: %d\nTies: %d", win, loss, tie);
  return;
}
//Prints out the scores from only games won by you
void games_won(int array [] [3]) {
    int i, j;
    for (i = 0; i < 2; i++) {
      for (j = 0; j < 3; j++) {
        if (array [0] [j] > array [1] [j]) {
        printf("%d ", array [i] [j]);
      }
    }
    printf("\n");
  }
  return;
}
//Sorts opps scores from lowest to highest
void scores_sort(int array [] [3]) {
    int i, j, temp, score [3];
    for (i = 1; i < 2; i++) {
      for (j = 0; j < 3; j++) {
        score [j] = array [i] [j];
  }
}
    for (j = 0; j < 3; j++) {
      for (i = j + 1; i < 3; i++) {
        if (score [j] > score [i]) {
          temp = score [j];
          score [j] = score [i];
          score [i] = temp;
        }
      }
    }
    for (j = 0; j < 3; j++) {
      printf("%d", score [j]);
  }
  return;
}