#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "POKIPOKI.h"

void pokemonFill(pokemon* log);
void pokemonRead(pokemon log);
void pokemonSearch(pokemon* log);
void pokemonDelete();

int main() {
  pokemon* pokedex = malloc(8001 * sizeof(pokedex));
  int entry;
  do {
  printf("Welcome to PokeDex 0.1a\n");
  printf("Please choose an option\n");
  printf("1. Record Entry\n");
  printf("2. View Entries\n");
  printf("3. Search Entries\n");
  printf("4. Delete Entries\n");
  printf("5. Quit\n");
  scanf("%i", &entry);

  switch (entry)
  {
  case 1:
    pokemonFill(pokedex);
    break;
  case 2:
    pokemonRead(*pokedex);
    break;
  case 3:
    pokemonSearch(pokedex);
    break;
  case 4:
    pokemonDelete();
    printf("File contents deleted\n");
    break;
  default:
    break;
  }

  } while (entry !=5);
}

void pokemonFill(pokemon* log) {
  pokemon pokeArray[151];//Static Array for inital storage
  int size, i;
  FILE *ab = fopen("pokedex.bin", "ab");//Readying bin file

  printf("Entries to record: ");
  scanf("%i", &size);//Choose how many to add to array

  for (i = 0; i < size; i++) {
    printf("Enter Pokemon Name: ");
    scanf("%s", pokeArray[i].name);
    printf("\nEnter Pokemon Type: ");
    scanf("%s", pokeArray[i].typing);
    printf("\nEnter Pokemon Height: ");
    scanf("%f", &pokeArray[i].height);
    printf("\nEnter Pokemon Weight: ");
    scanf("%f", &pokeArray[i].weight);//Create pokemon
  }

    for (i = 0; i < size; i++) {
      memcpy(&log[i].name, &pokeArray[i].name, sizeof(pokeArray));
      memcpy(&log[i].typing, &pokeArray[i].typing, sizeof(pokeArray));
      memcpy(&log[i].height, &pokeArray[i].height, sizeof(pokeArray));
      memcpy(&log[i].weight, &pokeArray[i].weight, sizeof(pokeArray));
      fwrite(&log[i], sizeof(log), 4, ab);//Fill dynamic array

      printf("Pokemon Name: %s\n", log[i].name);
      printf("Pokemon Type: %s\n", log[i].typing);
      printf("Pokemon Height: %f\n", log[i].height);
      printf("Pokemon Weight: %f\n", log[i].weight);
    }//Show/Confirm Log

  fclose(ab);
}

void pokemonRead(pokemon log) {
  FILE *rb = fopen("pokedex.bin", "rb");
  while(fread(&log, sizeof(&log), 4, rb)) {//Print stored Pokemon
    printf("Name: %s, Type: %s, Height %.2lf, Weight: %.2lf\n", log.name, log.typing, log.height, log.weight);
  }
  fclose(rb);
}

void pokemonSearch(pokemon* log) {
  char *search;
  int result;

  printf("Enter Pokemon to search for: ");
  scanf("%s", search);

  for (int i = 0; i < sizeof(log); i++) {
    result = strcmp(search, log[i].name);
    if (result == 0) {//Once Pokemon is found display it
      printf("Name: %s, Type: %s, Height %.2lf, Weight: %.2lf\n", log[i].name, log[i].typing, log[i].height, log[i].weight);
    }
  }
}

void pokemonDelete() {
  FILE *wb = fopen("pokedex.bin", "wb");
  printf("Entries deleted!\n");

  fclose(wb);//Delete current entries
}