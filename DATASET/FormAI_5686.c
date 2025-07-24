//FormAI DATASET v1.0 Category: Error handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // Initialize array of error codes
  int error_codes[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  
  printf("Enter the error code you wish to encounter: ");
  
  // Read in user input
  int user_input;
  scanf("%d", &user_input);
  
  // Check if user input is within valid range
  if (user_input < 0 || user_input > sizeof(error_codes) / sizeof(int) - 1) {
    printf("Error: Invalid error code entered!\n");
    exit(1); // Exit program with error
  }
  
  // Generate random number to determine if error will occur
  int random_num = rand() % 10;
  
  // Check if error will occur
  if (random_num == 0) {
    printf("Error %d occurred!\n", error_codes[user_input]);
    exit(1); // Exit program with error
  } else {
    printf("No error occurred. You lucked out this time!\n");
    return 0; // Exit program normally
  }
}