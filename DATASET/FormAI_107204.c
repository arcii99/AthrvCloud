//FormAI DATASET v1.0 Category: Syntax parsing ; Style: happy
#include <stdio.h>

int main() {
  printf("Hi! I'm a happy C Syntax parsing program!\n");
  
  char input[1000];
  printf("Please enter some C code for me to parse:\n");
  scanf("%[^\n]", input);

  // Let's parse the code and find any for loops
  int forCount = 0;
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == 'f' && input[i+1] == 'o' && input[i+2] == 'r') {
      forCount++;
    }
  }

  printf("Yay! I found %d for loops in your C code.\n", forCount);

  // Let's parse the code again and find any printf statements
  int printCount = 0;
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == 'p' && input[i+1] == 'r' && input[i+2] == 'i' && input[i+3] == 'n' && input[i+4] == 't' && input[i+5] == 'f') {
      printCount++;
    }
  }

  printf("Awesome! You have %d printf statements in your C code.\n", printCount);

  // Let's parse the code one more time and find any switch statements
  int switchCount = 0;
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == 's' && input[i+1] == 'w' && input[i+2] == 'i' && input[i+3] == 't' && input[i+4] == 'c' && input[i+5] == 'h') {
      switchCount++;
    }
  }

  printf("Wow! There are %d switch statements in your C code.\n", switchCount);

  printf("Thank you for letting me parse your code. Have a happy day!\n");
  return 0;
}