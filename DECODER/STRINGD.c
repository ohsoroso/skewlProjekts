#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  const char uncoded[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  const char decoded[] = {'h', 'i', 'v', 'j', 'k', 'w', 'l', 'a', 'm', 'y', 'n', 'b', 'x', 'o', 'z', 'c', 't', 'p', 'u', 'd', 'q', 's', 'r', 'e', 'g', 'f'};
  char decrypt[100];
  char encrypt[100];
  int i, j = 0;

  printf("Enter a string to be encoded: ");
  fgets(decrypt, 100, stdin);
  puts(decrypt);

  strcpy(encrypt, decrypt);
    
  for (i = 0; i < sizeof(uncoded); i++) {
    if (encrypt[j] == uncoded[i]) {
      encrypt[j] = decoded[i];
      j++;
      i = -1;
    }
  }
  puts(encrypt);
  return 0;
}