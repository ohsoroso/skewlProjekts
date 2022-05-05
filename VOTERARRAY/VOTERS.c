#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "VOTERS.h"

int firstUpper(char str[], int n);

int main() {
  int size, choice, winCount = 0;
  char weightClass[10], small[] = "Skinny", medium[] = "Fit", large[] = "FAT";
  VOTER voteArray[200];
  VOTER* voters = malloc(8001 * sizeof(*voters));

  do { //Initalize menu
  printf("What would you like to do?\n");
  printf("1. Read from file\n");
  printf("2. Write to file\n");
  printf("3. Quit\n");
  printf("Enter option here: ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:// Read all entries
  FILE *rp = fopen("VOTERS.bin", "rb");
    while(fread(voters, sizeof(voters), 6, rp)) {

    if (voters->weight < 125 && voters->gender == 'M' || 
        voters->weight < 100 && voters->gender == 'F' || 
        voters->weight < 115 && voters->gender == 'O' || 
        voters->gender == 'U') {
      strcpy(weightClass, small);
    }
    else if (voters->weight >= 125 && voters->gender == 'M' && voters->weight <= 225 || 
             voters->weight >= 100 && voters->gender == 'F' && voters->weight <= 150 || 
             voters->weight >= 115 && voters-> gender == 'O' || voters->gender == 'U' && voters->weight <= 200) {
      strcpy(weightClass, medium);
    }
    else if (voters->weight > 225 && voters->gender == 'M' || 
             voters->weight > 150 && voters->gender == 'F' || 
             voters->weight > 200 && voters->gender == 'O' || 
             voters->gender == 'U') {
      strcpy(weightClass, large);
    }//Determine weight classes

    srand(time(NULL));
    for (int i = 0; i < 500; i++) {
      int random = rand() % 999 / 1;
      if (voters->favNum == random) {
        winCount++;
      }// Lottrery simulator
    }

    printf("First: %s, Middle: %c, Last %s, Sex: %c, Favorite Number: %d, Times Won: %d, Weight: %.2f, Weight Class: %s\n", 
    voters->name.first, voters->name.mid, voters->name.last, 
    voters->gender, voters->favNum, winCount, voters->weight, weightClass);
  }
    
    fclose(rp);

    break;

  case 2:// Write to array
  FILE *ab = fopen("VOTERS.bin", "ab");
    printf("Number of entries: ");
    scanf("%d", &size);

  for (int i = 0; i < size; i++) {
    printf("\nEnter first name: ");
    scanf("%s", &voteArray[i].name.first);
    int n1 = sizeof(voteArray[i].name.first)/sizeof(voteArray[i].name.first[0]);
    firstUpper(voteArray[i].name.first, n1);//Capitalize first letter

    printf("\nEnter middle initial: ");
    scanf("%s", &voteArray[i].name.mid);
    int n2 = sizeof(voteArray[i].name.mid)/sizeof(voteArray[i].name.mid);
    firstUpper(&voteArray[i].name.mid, n2);// ^

    printf("\nEnter last name: ");
    scanf("%s", &voteArray[i].name.last);
    int n3 = sizeof(voteArray[i].name.last)/sizeof(voteArray[i].name.last[0]);
    firstUpper(voteArray[i].name.last, n3);// ^

    printf("\nEnter gender: ");
    scanf("%s", &voteArray[i].gender);

  if (&voteArray[i].gender != "M" && &voteArray[i].gender != "F" && &voteArray[i].gender != "O") {
    strcpy(&voteArray[i].gender, "U");// Assign unkown gender to incorrect entries
  }

    printf("\nEnter favorite number: ");
    scanf("%d", &voteArray[i].favNum);

  while (voteArray[i].favNum < 0 || voteArray[i].favNum > 999) {// User case errors
    printf("\nEnter favorite number: ");
    scanf("%d", &voteArray[i].favNum);
  }

    printf("\nEnter weight: ");
    scanf("%f", &voteArray[i].weight);

  while (voteArray[i].weight < 10.0 || voteArray[i].weight > 999.0) {// User case errors
    printf("\nEnter weight: ");
    scanf("%f", &voteArray[i].weight);
  }

  }
  for (int i = 0; i < size; i++) {// Copy to dynamic array
    memcpy(&voters[i].name.first, &voteArray[i].name.first, sizeof(voteArray));
    memcpy(&voters[i].name.mid, &voteArray[i].name.mid, sizeof(voteArray));
    memcpy(&voters[i].name.last, &voteArray[i].name.last, sizeof(voteArray));
    memcpy(&voters[i].gender, &voteArray[i].gender, sizeof(voteArray));
    memcpy(&voters[i].favNum, &voteArray[i].favNum, sizeof(voteArray));
    memcpy(&voters[i].weight, &voteArray[i].weight, sizeof(voteArray));
    fwrite(&voters[i], sizeof(voters), 6, ab);
  }


  fclose(ab);

  break;

  case 3:
    free(voters);
    exit(2);
  
  default:
    printf("Invalid choice please try again");
    break;
  }
} while (choice != 3);
}

int firstUpper(char str[], int n) {// Capitalize forst letter function
   int i;
   for(i = 0; i<n; i++) {
      if (i == 0 && str[i] != ' ' || str[i] != ' ' && str[i-1] == ' ') {
         if(str[i] >= 'a' && str[i]<='z') {
            str[i] = (char)(('A'-'a') + str[i] );
         }
      } else if (str[i] >= 'A' && str[i] <= 'Z') {
         str[i] = (char)(str[i] + ('a' - 'A'));
      }
   }
   return 0;
}