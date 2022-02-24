#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void printString(char str [100]) {
    puts(str);
}

void reverseString(char str [100]) {  
    int i, len, temp;  
    len = strlen(str); //Get the length of the string  
      
    // use for loop to iterate through the string   
    for (i = 0; i < len/2; i++)  
    {  
        // temp variable use to temporary hold the string and swap
        temp = str[i];  
        str[i] = str[len - i - 1];  
        str[len - i - 1] = temp;  
    }
    puts(str);
}  

void stringRange(char str [100]) {
    //Find length and turn it into a number
    int length = strlen(str);
    //Print number
    printf("%d\n", length);
}

void stringamid(char str [100]) {
    int i, j, length; 
    //Get length for rows
    length = strlen(str);
    //Loop thorugh and print letters equal to rows
    for ( i = 0 ; i < length ; i++ ) {
      for(j = length; j > i; j--) {
        //Print spaces where letter would be
        printf(" ");
    }
      //Print letters where they need to be for pyramid
      for( j = 0 ; j <= i ; j++ ) {
        printf("%c", str[j]);
        printf(" ");
    }
        printf("\n");
  }
}

void verticalString(char str [100]) {
    int j = 0, i;
    //Loop through one letter at a time
    for(i = 0; i < str[j]; i++) {
        //Print each letter on one line
        printf("%c\n", str[j++]);
    }
}

void verticalString(char str [100]);
void pyramidString(char str [100]);
void stringRange(char str [100]);
void stringamid(char str [100]);

int main() {
char isslit [100];
int answer, i;
  do {
  printf("Enter text here: ");
  scanf("%s", isslit);

  for (i = 0; i < sizeof(isslit); i++) {
    if(isslit[i] >= '0' && isslit[i] <= '9') {
      printf("Invalid entry please try again.\n");
      printf("Enter text here: ");
      scanf("%s", isslit);
    }
  }
  
  stringamid(isslit);
  printString(isslit);
  verticalString(isslit);
  reverseString(isslit);
  stringRange(isslit);
  
  printf("Would you like to enter another word?\n");
  printf("1. Yes\n2. No\n");
  scanf("%d", &answer);
  } while (answer != 2);
}