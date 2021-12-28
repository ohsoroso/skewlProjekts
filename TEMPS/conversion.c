#include <stdio.h>
#include <stdlib.h>

int celsToFaren(int input) { //Celsius Conversion
    int result;
    result = ((input * 9)/5) + 32;
    return result;
}

int farenToCels(int input) { //Fahrenheit Conversion
    int result;
    result = ((double) 5 / 9) * (input - 32);
    return result;
}

int main() {
    
    int n;
    double temp, cels, faren;
    
    do { //Gather user input and create menu options
    printf("Temperature Conversion\n");
    printf("Would you like to:\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Quit\n");
    scanf("%d", &n);
    
    switch(n) { //Gather further user input and calculate results
        case 1: printf("Enter a number to be converted:\n");
                scanf("%lf", &temp);
                faren = farenToCels(temp);
                printf("%.2lf converted to celsius is %.2lf\n", temp, faren);
                break;
                
        case 2: printf("Enter a number to be converted:\n");
                scanf("%lf", &temp);
                cels = celsToFaren(temp);
                printf("%.2lf converted to fahrenheit is %.2lf\n", temp, cels);
                break;
                
        case 3: printf("Goodbye !\n");
                break;
                
        default: printf("Not a valid option YA GOOF !\n");
                 break;
              }
       } while (n != 3);

    return 0;
}