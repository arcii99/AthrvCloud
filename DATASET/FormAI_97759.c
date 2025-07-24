//FormAI DATASET v1.0 Category: Data validation ; Style: funny
#include <stdio.h>

int main() {
  int user_input;
  printf("Enter a number between 1 and 10: ");
  scanf("%d", &user_input);
  
  if (user_input < 1 || user_input > 10) {
    printf("Invalid input! You did not follow the instructions.\n");
  } else {
    printf("Congratulations! You followed the instructions!\n");
  }
  return 0;
}