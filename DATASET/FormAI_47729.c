//FormAI DATASET v1.0 Category: Data validation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  char input[10];
  int num;
  while (1) {
    printf("Please enter a number between 1 and 10: ");
    fgets(input, 10, stdin); // Get user input
    // Check if input is valid
    if (strlen(input) == 2 && isdigit(input[0])) { // 1 digit input
      num = input[0] - '0';
      if (num >= 1 && num <= 10) {
        printf("You entered the number %d.\n", num);
        break;
      }
    } else if (strlen(input) == 3 && isdigit(input[0]) && isdigit(input[1])) { // 2 digit input
      num = (input[0] - '0') * 10 + (input[1] - '0');
      if (num >= 1 && num <= 10) {
        printf("You entered the number %d.\n", num);
        break;
      }
    }
    // Input is not valid, ask user to try again
    printf("Input invalid. Please try again.\n");
  }
  return 0;
}