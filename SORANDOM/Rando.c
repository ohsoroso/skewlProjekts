#include <stdio.h>
#include <ctype.h>

int main() {
  int iRandomNumbah = 0;
  int iMyNumbah = 0;
  srand(time(NULL));
  iRandomNumbah = (rand() % 100) + 1;

  printf("\nWEEELCOOOOOME TO Pick THAT Numbah!\n");
  printf("Now\nPick\nThat\nNUMBAH!\n");
  scanf("%d", &iMyNumbah);

  if isdigit(iMyNumbah == iRandomNumbah) {
      printf("\nLADIES AND GENTLEMEN WE HABE A WINNER!!!\n");
  }
    else {
      printf("\nOOF\nSORRY YOU ARE WRONG AND YOU SHOULD FEEL BAD.\n");
      printf("The correct number was %d\n", iRandomNumbah);
    }
  system("pause");
  return 0;
}