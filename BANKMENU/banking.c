#include <stdio.h>
#include <stdlib.h>
//Swap function for BubbleSort
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
//Setting up BubbleSort to be used
void bubbleSort(int arr[], int n) {
int i, j;
   for (i=0; i < n-1; i++)      

        
       for (j=0; j < n-i-1; j++) 
           if (arr[j] < arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
//Quick print
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
  int deposit, sum = 0, totalSum = 0, avrg = 0, i = 0, j = 0, n, low;
  int deposits [5];
  char choice;
do {//Menu options
printf("rosocorp ATM Services how may we help you today ?\n");
printf("[G]et a new deposit\n");
printf("[S]um of all deposits\n");
printf("[D]eposits will be displayed from highest to lowest deposit\n");
printf("[A]verage of all deposits\n");
printf("[L]owest deposit will be displayed\n");
printf("[Q]uit the program\n");
scanf("%s", &choice);
//Menu calls
switch (choice) {
case 'G'://Set and store individual deposits
  printf("Enter deposit amount:");
  scanf("%d", &deposit);
  printf("Your deposit was: %d\n", deposit);
  for (i = i; i < 5; i++) {
      deposits[i] = deposit;
      break;
  }
  i++;
  break;

case 'S'://Sum deposits
  for (i = 0; i < 5; i++) {
      sum += deposits[i];
  }
  printf("\nThe sum of all deposits is: %d\n", sum);
  break;
  
case 'D'://Deposits highest to lowest using BubbleSort
n = sizeof(deposits)/sizeof(deposits[0]);
bubbleSort(deposits, n);
printf("Deposits highest to lowest: \n");
printArray(deposits, n);
  break;
  
case 'A'://Average deposits
  for (i = 0; i < 5; i++) {
      totalSum += deposits[i];
  }
  avrg = totalSum / 5;
  printf("\nAverage is: %d\n", avrg);
  break;
  
 case 'L'://Finding lowest deposit
 n = sizeof(deposits)/sizeof(deposits[0]);
 low = deposits[0];
   for ( i = 0; i < n; i++) {
       if (deposits[i] < low) {
           low = deposits[i];
       }
   }
   printf("The lowest deposit was: %d\n", low);
   break;

default:
  break;
}
} while (choice != 'Q');
  return 0;
}
