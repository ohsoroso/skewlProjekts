#include <stdio.h>

int main() {
  int legalAge = 21;
  int userAge = 0;
  printf("How old are ya?: ");
  scanf("%d", &userAge);
  if (userAge<legalAge)
  {
    printf("\n You are a minor goofball, no alchohol for you! \n");
  }
  else printf("\n Enjoy our fine slection of liver killer!");
  system("pause");
  return 0;
}
