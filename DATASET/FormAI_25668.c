//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int sanitize_input(int input) {
  while(1) {
    if(input != 0 && input / abs(input) == 1) { 
        return input;
    }
    else {
        printf("Invalid input! Please enter a valid integer: ");
        scanf("%d", &input);
    }
  }
}

int main() {
  printf("Please enter an integer: ");
  int input;
  scanf("%d", &input);
  int sanitized_input = sanitize_input(input);
  printf("Sanitized input: %d\n", sanitized_input);
  return 0;
}