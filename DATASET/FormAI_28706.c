//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: portable
#include <stdio.h>
#include <string.h>

int main() {
  
  char input[100];
  int length = 0;
  
  printf("Enter a phrase in C Cat Language: ");
  fgets(input, 100, stdin);
  length = strlen(input);
  
  for (int i = 0; i < length; i++) {
    
    if (input[i] == 'M') {
      printf("Meow ");
    }
    else if (input[i] == 'P') {
      printf("Purr ");
    }
    else if (input[i] == 'H') {
      printf("Hiss ");
    }
    else if (input[i] == 'C') {
      printf("Chirp ");
    }
    else if (input[i] == 'Y') {
      printf("Yowl ");
    }
    else if (input[i] == ' ') {
      printf(" ");
    }
    else {
      printf("Invalid character! ");
    }
    
  }
  
  return 0;
}