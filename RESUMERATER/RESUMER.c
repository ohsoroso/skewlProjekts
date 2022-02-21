#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   FILE *fp1;
   FILE *fp2;
long length;
char *b1;
char *b2;
int count=0;

fp1 = fopen( "keyw.txt" , "r" );
if (fp1)
{
  fseek(fp1, 0, SEEK_END);
  length = ftell(fp1);
  fseek(fp1, 0, SEEK_SET);
  b1 = malloc(length);
  if (b1)
  {
    fread(b1, 1, length, fp1);
  }
  fclose(fp1);
  b1[length] = '\0';
}

fp2 = fopen( "resume.txt" , "r" );
if (fp2)
{
  fseek(fp2, 0, SEEK_END);
  length = ftell(fp2);
  fseek(fp2, 0, SEEK_SET);
  b2 = malloc(length);
  if (b2)
  {
    fread(b2, 1, length, fp2);
  }
  fclose(fp2);
  b2[length] = '\0';
}

char *t1 = strtok(b1, ",");

do {
    if (strstr(b2, t1)) {
        printf("Match: %s\n", t1);
        count++;
    }
    t1 = strtok(NULL, ",");
} while (t1 != NULL);
    printf("There was %d matches", count);
    return 1;
}