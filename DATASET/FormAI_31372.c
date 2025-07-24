//FormAI DATASET v1.0 Category: Error handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
  
  char input;

  printf("Please choose a number: ");
  scanf("%c", &input);

  if(input < '0' || input > '9') {
    printf("Error: Invalid input. You did not enter a number.\n");
    exit(1); // exit with error status
  }
  
  int num = input - '0';

  if(num % 2 == 0) {
    printf("You entered an even number.\n");
  }
  else {
    printf("You entered an odd number.\n");
  }

  return 0;
}