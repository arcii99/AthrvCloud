//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_character(char character, int size) {
  int i, j;
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      printf("%c", character);
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: ascii-art <character> <size>\n");
    return 1;
  }

  char *character = argv[1];
  int size = atoi(argv[2]);

  if (strlen(character) != 1) {
    printf("Error: Character must be a single character\n");
    return 1;
  }

  if (size < 1 || size > 10) {
    printf("Error: Size must be between 1 and 10\n");
    return 1;
  }

  printf("Generating ASCII art for character '%s' with size '%d'\n", character, size);
  print_character(character[0], size);

  return 0;
}