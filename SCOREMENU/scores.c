#include <stdio.h>
#include <stdlib.h>

//Declare functions
void display_menu(void);
void game_result(void);
void list_scores(void);
void games_won(void);
void scores_sort(void);

int main() {
    int teams = 2, score = 100, game [teams] [score], i, j;
    
    //Call menu
    display_menu();

    return 0;
}

//Display menu options
void display_menu(void) {
    int teams = 2, score = 100, game [teams] [score], i, j;
    char choice;
    
    do
    {
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
            case 'A': game_result();
                break;
            /*case 'B': list_scores();
                break;
            case 'C': games_won();
                break;
            case 'D': scores_sort();
                break;*/
            case 'E': printf("Quitting program!\n");
                exit(0);
                break;
            default: printf("Invalid choice!\n");
                break;
        }
        
    } while (choice != 'E');
    
}

//Begin function items
void game_result(void) {
int teams = 2, score = 100, game [teams] [score], i, j;
    
    printf("Enter your stuf: \n");
    for (i = 0; i < teams; i++)
      for (j = 0; j < score; j++) {
        scanf("%d", &game [i] [j]);
        break;
      }
    return;
}