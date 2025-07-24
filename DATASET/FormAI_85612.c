//FormAI DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>

int main() {
  printf("Welcome to the Curious Number Game!\n");
  printf("Think of a number between 1 and 100 and I will try to guess it.\n");
  
  int guess = 50;
  int lower_bound = 1;
  int upper_bound = 100;
  char response;
  
  while (1) {
    printf("Is your number %d? (y/n)\n", guess);
    scanf(" %c", &response);
    
    if (response == 'y') {
      printf("Yay! I guessed your number.\n");
      break;
    } else if (response == 'n') {
      printf("Is your number higher or lower than %d? (h/l)\n", guess);
      scanf(" %c", &response);
      
      if (response == 'h') {
        lower_bound = guess + 1;
        guess = (lower_bound + upper_bound) / 2;
      } else if (response == 'l') {
        upper_bound = guess - 1;
        guess = (lower_bound + upper_bound) / 2;
      } else {
        printf("Invalid response.\n");
      }
    } else {
      printf("Invalid response.\n");
    }
  }
  
  return 0;
}