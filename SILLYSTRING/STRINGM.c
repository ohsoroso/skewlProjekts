#include <stdio.h>
#include <stdlib.h>

void printString(char str [100]) {
    puts(str);
}
void reverseString(char str [100]) {
    
}
void verticalString(char str [100]);
void pyramidString(char str [100]);
void stringRange(char str [100]);

int main() {
char isslit [100];

  printf("Enter text here: ");
  fgets(isslit, sizeof(isslit), stdin);
  
  printString(isslit);
  reverseString(isslit);
}