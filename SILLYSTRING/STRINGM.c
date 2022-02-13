#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printString(char str [100]) {
    puts(str);
}

void reverseString(char str [100])  
{  
    // declare variable  
    int i, len, temp;  
    len = strlen(str); // use strlen() to get the length of str string  
      
    // use for loop to iterate the string   
    for (i = 0; i < len/2; i++)  
    {  
        // temp variable use to temporary hold the string  
        temp = str[i];  
        str[i] = str[len - i - 1];  
        str[len - i - 1] = temp;  
    }
    puts(str);
}  

void stringRange(char str [100]) {
    int length = strlen(str);
    printf("%d", length);
}

void stringamid(char str [100]) {
    int n, a = 0;
    for(int i=0;i<=n;i++)
   {
     // for space 
     for(int j=0;j<=n-i;j++) 
     printf(" "); // print space

     for(int k=0;k<=i;k++)
     {
        // print character
        printf("%2c", str[a++]);

        // if index reach end of string then again
        // it should start from initial characters
        if(str[a]=='\0') a=0;
     }

     printf("\n"); // new line
   }
}

void verticalString(char str [100]);
void pyramidString(char str [100]);
void stringRange(char str [100]);
void stringamid(char str [100]);

int main() {
char isslit [100];

  printf("Enter text here: ");
  scanf("%s", isslit);
  
  printString(isslit);
  reverseString(isslit);
  stringRange(isslit);
  stringamid(isslit);
}