#include <stdio.h>
#include <stdlib.h>

// Declare functions
void game_result(int array [] [3]);
void list_scores(int array [] [3]);
void games_won(int array [] [3]);
void scores_sort(int array [] [3]);

int main() {
int game [2] [3], i, j;
char choice;

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
        scanf("%c",&choice);
        
        // set menu options
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
                exit(0);
                break;
            default: printf("Invalid choice!\n");
                break;
        }
        
    } while (choice != 'E');
return 0;
}

void game_result(int array [] [3]) {
    int i, j;
    printf("Enter scores: \n");
    for (i = 0; i < 2; i++) {
      for (j = 0; j < 3; j++) {
        scanf("%d", &array [i] [j]);
      }
    }
  return;
}

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

void games_won(int array [] [3]) {
    int i, j, winset [2] [3];
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        if (array [0] [j] > array [1] [j]) {
        winset [i] [j] = array [i] [j];
      }
    }
  }
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
    printf("%d\n", winset [i] [j]);
    }
  }
  return;
}

void scores_sort(int array [] [3]) {
    int i, j, score [3];
    for (i = 1; i < 2; i++) {
      for (j = 0; j < 3; j++) {
        if (array [1] [j] < array [1] [j + 1]) {
          score [j] = array [i] [j];
        }
      }
    }
}