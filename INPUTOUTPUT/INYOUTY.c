#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char yaynay, choice, i;
  char entry [1000];
  FILE *pRead;
  FILE *pWrite;
  FILE *pAppend;
  pRead = fopen("memi.txt", "r");
  if (pRead == NULL) {
    printf("File not found.\nWould you like to create one?\n");
    printf("Y/N: ");
  scanf(" %c", &yaynay);
  if (yaynay == 'Y' || yaynay == 'y') {
    pWrite = fopen("memi.txt", "w");
    fclose(pWrite);
    printf("File created.");
  }
  else if (yaynay == 'N' || yaynay == 'n') {
    printf("Exiting program...");
    return 0;
  }
  else {
      printf("Invalid entry, please try again.");
  }
 }
  else {
      printf("File found, loading...");
  }
  do {
  printf("\n\n*************************\n");
  printf("**      MAIN MENU     ***\n");
  printf("*************************\n\n");
  printf("[A]Enter words\n");
  printf("[B]Add words\n");
  printf("[C]Dump all words\n");
  printf("[D]Read current words\n");
  printf("[E]Quit the program \n");
  printf("Enter an option: ");
  scanf(" %c", &choice);
  
  switch(choice) {
      case 'a':
      case 'A': fopen("memi.txt", "w");
                printf("Enter up to 1000 words: ");
                getchar();
                if(fgets(entry, sizeof(entry) + 1, stdin) != NULL)
                fprintf(pWrite, "%s", entry);
                fclose(pWrite);
                break;
                
      case 'b':
      case 'B': pAppend = fopen("memi.txt", "a");
                printf("Add some words: ");
                getchar();
                if(fgets(entry, sizeof(entry) + 1, stdin) != NULL)
                  fprintf(pWrite, "%s", entry);
                fclose(pAppend);
                break;
                
      case 'c':
      case 'C': printf("Dumping all words...");
                pWrite = fopen("memi.txt", "w+");
                fclose(pWrite);
                printf("Words dumped.");
                break;
                
      case 'd':
      case 'D': pRead = fopen("memi.txt", "r");
                printf("Loading words for reading...\n");
                i = fgetc(pRead);
                while (i != EOF) {
                  printf ("%c", i);
                  i = fgetc(pRead);
                }

                if (fgetc(pRead = NULL)) {
                  printf("Nothing found please enter text.");
                }
  
                fclose(pRead);
                break;

      default: printf("Invalid entry please try again.");
                
  }
 } while (choice != 'E');
}