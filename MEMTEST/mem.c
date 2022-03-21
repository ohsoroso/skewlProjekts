/*Zakary Smith
  03/11/2022
  Program to demonstrate creating memory on stack and heap
  and outputting heap memory to a bin file.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem.h"

int main() {
  ASL hoom[1000];
  int entries, i;
  FILE *writer;
  writer = fopen("mem.bin", "wb");
  printf("How many entries? ");
  scanf("%d", &entries);
  
  for (i = 0; i < entries; i++) {
    printf("Enter age: ");
    scanf("%d", &hoom[i].age);

  while (hoom[i].age < 1 || hoom[i].age > 125) {//Validation
    printf("Invalid entry, please try again!");
    printf("Enter age: ");
    scanf("%d", &hoom[i].age);
  }

    printf("\nEnter sex: ");
    scanf("%s", &hoom[i].sex);

  while (hoom[i].sex != 'f' && hoom[i].sex != 'F' && hoom[i].sex != 'm' && hoom[i].sex != 'M') {//Validation
    printf("Invalid entry, please try again!");
    printf("\nEnter sex: ");
    scanf("%s", &hoom[i].sex);
  }

    printf("\nEnter location: ");
    scanf("%s", hoom[i].loc);

  while (strlen(hoom[i].loc) > 2) {//Valdidation
    printf("Please use two letter state codes only!");
    printf("\nEnter location: ");
    scanf("%s", hoom[i].loc);
   } 
  }

  printf("Stack Array:\n");
  for (i = 0; i < entries; i++) {
    printf("Age: %d, Sex: %c, Location %s\n", hoom[i].age, hoom[i].sex, hoom[i].loc);
  }
  printf("\n");

  ASL* heapHoom = malloc(8001 * sizeof(*heapHoom));//Creating dynamic array

  printf("Heap Array:\n");
  for (i = 0; i < entries; i++) {//Copying stack to heap
    memcpy(&heapHoom[i].age, &hoom[i].age, sizeof(hoom)+1);
    memcpy(&heapHoom[i].sex, &hoom[i].sex, sizeof(hoom)+1);
    memcpy(&heapHoom[i].loc, &hoom[i].loc, sizeof(hoom)+1);
  }

  for (i = 0; i < entries; i++) {
    printf("Age: %d, Sex: %c, Location %s\n", heapHoom[i].age, heapHoom[i].sex, heapHoom[i].loc);
  }

  fwrite(heapHoom, entries * sizeof(heapHoom), 1, writer);//Writing to bin file

  free(heapHoom);//Free that memory!!!
}