#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "info.h"

person fillName(person *h1, person *h2, person *h3);
void fillHuman(person *h1, person *h2, person *h3);
DATE fillDate();
void displayHuman(person h1, person h2, person h3);
void displayDate(DATE birthday);
float fillAnnualIncome(person *h1, person *h2, person *h3);
char fillSex(person *h1, person *h2, person *h3);

int main() {
    person h1, h2, h3;
    DATE birthday;
  
    fillHuman(&h1, &h2, &h3);
    displayHuman(h1, h2, h3);
  
}

person fillName(person *h1, person *h2, person *h3) {
    person result;
    printf("Enter first names: ");
    scanf("%s", result.name);
    return result;
}

DATE fillDate() {
    DATE result;
    printf("Enter birth month: ");
    scanf("%d", &result.month);
    
    printf("Enter birth day: ");
    scanf("%d", &result.day);
    
    printf("Enter birth year: ");
    scanf("%d", &result.year);
    return result;
}

char fillSex(person *h1, person *h2, person *h3) {
    char result;
    printf("Enter gender: ");
    scanf("%s", &result);
    return result;
}

float fillAnnualIncome(person *h1, person *h2, person *h3) {
    float result;
    printf("Enter annual income: ");
    scanf("%f", &result);
    return result;
}

void displayDate(DATE birthday) {
    printf("\n\t%i/%i/%i\n", birthday.month, birthday.day, birthday.year);
}
void fillHuman(person *h1, person *h2, person *h3) {
    h1->dob = fillDate();
    h1->sex = fillSex(&h1, &h2, &h3);
    h1->annIncome = fillAnnualIncome(&h1, &h2, &h3);
    
    h2->dob = fillDate();
    h2->sex = fillSex(&h1, &h2, &h3);
    h2->annIncome = fillAnnualIncome(&h1, &h2, &h3);
    
    h3->dob = fillDate();
    h3->sex = fillSex(&h1, &h2, &h3);
    h3->annIncome = fillAnnualIncome(&h1, &h2, &h3);
}
    
void displayHuman(person h1, person h2, person h3) {
    printf("First: %s", h1.name);
    displayDate(h1.dob);
}