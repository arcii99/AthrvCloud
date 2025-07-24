//FormAI DATASET v1.0 Category: Compression algorithms ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the Compress-O-Matic 3000, the only compression tool that's not afraid to clown around!\n");
  printf("Enter your string: ");
  char input[100];
  fgets(input, 100, stdin);
  
  int i = 0;
  int count = 0;
  char curr = input[0];
  printf("Compressed output: ");
  while (input[i] != '\n') {
    if (input[i] == curr) {
      count++;
    } else {
      printf("%c%d", curr, count);
      count = 1;
      curr = input[i];
    }
    i++;
  }
  printf("%c%d\n", curr, count);
  
  printf("Wow, your string just got compressed like a clown car! Who woulda thought computer science could be this much fun?\n");
  return 0;
}