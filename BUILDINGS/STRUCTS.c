#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "info.h"

//Prototype Functions
void displayDate(DATE birth);
void displayhumans(PERSON h1, PERSON h2, PERSON h3);
DATE fillDate();
float fillAnualIncome(PERSON *h1, PERSON *h2, PERSON *h3);
void fillThings(PERSON *h1, PERSON *h2, PERSON *h3);

//Main
int main() {
    DATE birth;
    PERSON human1, human2, human3;

    fillThings(&human1, &human2, &human3);
    displayhumans(human1, human2, human3);
}//End Main

//Write Functions
void displayDate(DATE birth) {
    printf("\n\t%d/%d/%d\n", birth.month, birth.day, birth.year);
}//End Display Date

void displayhumans(PERSON h1, PERSON h2, PERSON h3) {

    strcpy(h1.name, "Thunder");
    strcpy(h1.lastName, "Blunder");
    strcpy(h2.name, "Sir");
    strcpy(h2.lastName, "Dimetrious");
    strcpy(h3.name, "Vaati");
    strcpy(h3.lastName, "Vidya");

    printf("\n\tFirst: %s\n", h1.name);
    printf("\n\tLast: %s\n", h1.lastName);
    displayDate(h1.dob);
    printf("\n\tGender: %c\n", h1.sex);
    printf("\n\tAnual Income: %.2f\n", h1.anualIncome);

    printf("\n\tFirst: %s\n", h2.name);
    printf("\n\tLast: %s\n", h2.lastName);
    displayDate(h2.dob);
    printf("\n\tGender: %c\n", h2.sex);
    printf("\n\tAnual Income: %.2f\n", h2.anualIncome);

    printf("\n\tFirst: %s\n", h3.name);
    printf("\n\tLast: %s\n", h3.lastName);
    displayDate(h3.dob);
    printf("\n\tGender: %c\n", h3.sex);
    printf("\n\tAnual Income: %.2f\n", h3.anualIncome);

}//End Display humans

float fillAnualIncome(PERSON *h1, PERSON *h2, PERSON *h3) {
    float result;

    do {
        printf("\n\tEnter The Anual Income Of The human: ");
        scanf("%f", &result);
        if (result < 0 || result > 1000000)
            printf("Invalid Number--- Try Again\n");
    } while (result < 0 || result > 1000000);

    return result;
}

DATE fillDate() {
    DATE result;

    do {
        printf("\n\tEnter Year: ");
        scanf("%d", &result.year);
        if (result.year < 1900 || result.year > 5000)
            printf("\tInvalid Number--- Try Again\n");
    } while (result.year < 1900 || result.year > 5000);

    do {
        printf("\n\tEnter Month: *****Please enter single digit months as a single digit***** ");
        scanf("%d", &result.month);
        if (result.month < 0 || result.month > 12)
            printf("\tInvalid Number--- Try Again\n");
    } while (result.month < 0 || result.month > 12);

    do {
        printf("\n\tEnter Day: ");
        scanf("%d", &result.day);
        if (result.day < 1 || result.day > 31) {
                printf("\tInvalid Number--- Try Again\n");
        }
        if (result.month == 2 || result.month == 02) { //Check for leap year
            if (((result.year % 4 == 0) && result.year % 100 != 0) ||
                (result.year % 400 == 0)) {
                while (result.day < 1 || result.day > 29) { //Leap year feb dates 1-29
                    printf("\tLeap Year--- Try Again\n");
                    printf("\n\tEnter Day: ");
                    scanf("%d", &result.day);
                }
            }
            else {
                while (result.day < 1 || result.day > 28) { //Leap year feb dates 1-29
                    printf("\tInvalid Number--- Try Again\n");
                    printf("\n\tEnter Day: ");
                    scanf("%d", &result.day);
                }
            }
        }

        if (result.month == 4 || result.month == 6 || result.month == 9 || result.month == 11) {
            while (result.day < 1 || result.day > 30) {
                printf("\tInvalid Day--- Try Again\n");
                printf("\n\tEnter Day: ");
                scanf("%d", &result.day);
            }
        }
    } while (result.day < 1 || result.day > 31);

    return result;
}//End Get Date

char fillGender(PERSON *h1, PERSON *h2, PERSON *h3) {
    char result;
    do {
        printf("\n\tEnter The Gender For The human: ");
        scanf(" %c", &result);
        if (result != 'F' && result != 'f' && result != 'M' && result != 'm' && 
            result != 'O' && result != 'o')
            printf("\n\tERROR-- Try Again...\n");
    } while (result != 'F' && result != 'f' && result != 'M' && result != 'm' &&
        result != 'O' && result != 'o');

    return result;
}//End Get Gender

void fillThings(PERSON *h1, PERSON *h2, PERSON *h3) {

    printf("\n\tEnter The Date Of Birth Of Thunder: \n");
    h1->dob = fillDate();
    h1->sex = fillGender(&h1, &h2, &h3);
    h1->anualIncome = fillAnualIncome(&h1, &h2, &h3);

    printf("\n\tEnter The Date Of Birth Of Sir: \n");
    h2->dob = fillDate();
    h2->sex = fillGender(&h1, &h2, &h3);
    h2->anualIncome = fillAnualIncome(&h1, &h2, &h3);

    printf("\n\tEnter The Date Of Birth Of Vaati: \n");
    h3->dob = fillDate();
    h3->sex = fillGender(&h1, &h2, &h3);
    h3->anualIncome = fillAnualIncome(&h1, &h2, &h3);
}