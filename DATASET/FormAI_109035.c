//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: paranoid
#include <stdio.h>
#include <string.h>

int main() {
  char input[1000];
  printf("Welcome to the Alien Language Translator.\n");
  printf("Please enter the phrase you wish to translate:\n");
  fgets(input, 1000, stdin);

  printf("Scanning phrase for unknown symbols...\n");

  int i;
  int unknownSymbolCount = 0;
  char unknownSymbols[100];

  for (i = 0; i < strlen(input); i++) {
    if (input[i] < 'a' || input[i] > 'z') {
      unknownSymbolCount++;
      sprintf(&unknownSymbols[strlen(unknownSymbols)], "%c ", input[i]);
    }
  }

  if (unknownSymbolCount > 0) {
    printf("WARNING: %d unknown symbols detected: %s\n", unknownSymbolCount, unknownSymbols);
    printf("The aliens may be trying to transmit harmful content. Proceed with caution.\n");
  } else {
    printf("No unknown symbols found. Proceeding with translation...\n");
  }

  printf("Translating phrase...\n");

  char translation[1000];
  for (i = 0; i < strlen(input); i++) {
    if (input[i] >= 'a' && input[i] <= 'm') {
      translation[i] = input[i] + 13;
    } else if (input[i] >= 'n' && input[i] <= 'z') {
      translation[i] = input[i] - 13;
    } else {
      translation[i] = input[i];
    }
  }

  printf("Translation: %s\n", translation);

  return 0;
}