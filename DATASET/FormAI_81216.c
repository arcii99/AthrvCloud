//FormAI DATASET v1.0 Category: Robot movement control ; Style: enthusiastic
#include <stdio.h>

int main() {
  printf("Welcome to the Robot Movement Control Program!\n");
  printf("Please select a direction: (up, down, left, right)\n");
  
  char direction[10];
  scanf("%s", direction);
  
  printf("You have selected %s!\n", direction);
  
  if (strcmp(direction, "up") == 0) {
    printf("Moving up...\n");
    // Code for moving up
  }
  else if (strcmp(direction, "down") == 0) {
    printf("Moving down...\n");
    // Code for moving down
  }
  else if (strcmp(direction, "left") == 0) {
    printf("Moving left...\n");
    // Code for moving left
  }
  else if (strcmp(direction, "right") == 0) {
    printf("Moving right...\n");
    // Code for moving right
  }
  else {
    printf("%s is not a valid direction.\n", direction);
  }
  
  printf("Thank you for using Robot Movement Control Program!\n");
  
  return 0;
}