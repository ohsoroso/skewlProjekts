#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LINKER.h"

int listLength(STUDENT *head) {//Aqquire length of list
    int len = 0;
    STUDENT *count = head;
    while(count!=NULL)
    {
        len++;
        count=count->next;
    }

    return len;
}

void sortList(STUDENT *head) {//Sort linked list alphabetically and transfer other values
    int len = listLength(head);

    int i;
   
    for(i=0; i<len; i++)//Sort as long as the list is
    {
        STUDENT *tmp1 = head;
        STUDENT *tmp2 = (tmp1 != NULL) ? tmp1->next : NULL;
        while((tmp1 != NULL) && (tmp2 != NULL))
        {
            int idx = 0;
            if(strcmp(tmp1->name, tmp2->name) > 0)
            {
                char wrd[100];
                int age;
                float weight;
                strcpy(wrd, tmp1->name);
                strcpy(tmp1->name, tmp2->name);
                strcpy(tmp2->name, wrd);
                age = tmp1->age;
                tmp1->age = tmp2->age;
                tmp2->age = age;
                weight = tmp1->weight;
                tmp1->weight = tmp2->weight;
                tmp2->weight = weight;
            }
            tmp1=tmp1->next;
            tmp2 = tmp2->next;
        }
        tmp1 = head;
    }
}

int main() {
  LIST p = NULL, head = NULL, linkedList = NULL;
  int agep = 0, count = 1, counter, choice;
  char namep[30], response;
  float weightp;

do {
printf("What would you like to do:\n");
printf("1. Enter student info into the database.\n");
printf("2. Display the student data.\n");
printf("3. Exit the program.\n");
printf("Enter option here: ");
scanf(" %d", &choice);

switch (choice) {
case 1://Enter list info
do {//Store in local variables
  printf("Enter the name for student %d : ", count);
  scanf("%s[^\t\n]", namep);
  for (int i = 0; i < sizeof(namep); i++) {
    while (isdigit(namep[i]) == 1) {//User case errors
      printf("Invalid entry please try again\n");
      printf("Enter the name for student %d : ", count);
      scanf("%s[^\t\n]", namep);
    }
  }

  printf("\nEnter the age for %s: ", namep);
  scanf("%i", &agep);
  while (agep < 1 || agep > 120) {//User case errors
    printf("Invalid entry please try again\n");
    printf("\nEnter the age for %s: ", namep);
    scanf("%i", &agep);
  }
  

  printf("\nEnter the weight for %s: ", namep);
  scanf("%f", &weightp);
  while (weightp < 5 || weightp > 999) {//User case errors
    printf("Invalid entry please try again\n");
    printf("\nEnter the weight for %s: ", namep);
    scanf("%f", &weightp);
  }

if (count == 1) {//If first start the list
  linkedList = (LIST)malloc(sizeof(STUDENT));
  head = linkedList;
  strcpy(head->name, namep);
  head->age = agep;
  head->weight = weightp;
  head->next = NULL;
}

else {//Keep adding to list
  p = (LIST)malloc(sizeof(STUDENT));
  linkedList->next = p;
  linkedList = p;
  strcpy(p->name, namep);
  p->age = agep;
  p->weight = weightp;
  p->next = NULL;
  count++;
}

  printf("\nWould you like to enter another student?");
  printf("\nY/N :");
  scanf(" %c", &response);

  count += 1;

} while (response == 'Y' || response == 'y');
  break;
case 2://Print out list
  p = head;
  counter = 1;

while (p != NULL) {
  sortList(p);//Function for alphabetical sorting
  printf("Student %i: %s Age: %2i Weight: %.2f \n",
  counter, p->name, p->age, p->weight);
  counter += 1;
  p = p->next;
}

  printf("\n");
  break;
case 3:
  break;
default://Use case errors
  printf("That was not a valid choice.");
}

} while (choice != 3);

while (head != NULL) {//Free memory up
  p = head;
  head = head->next;
  free(p);
}
}