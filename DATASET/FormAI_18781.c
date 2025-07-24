//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: grateful
#include <stdio.h>

int main(void) {
  char user_input;
  int speed = 0;

  printf("Welcome to the C Drone Remote Control program!\n");

  while (1) {
    printf("Please select an option:\n");
    printf("a. Increase speed\n");
    printf("b. Decrease speed\n");
    printf("c. Hover in place\n");
    printf("d. Emergency stop\n");
    printf("e. Exit program\n");

    scanf(" %c", &user_input);
    
    if (user_input == 'a') {
      speed += 10;
      printf("Increasing speed by 10. Current speed: %d\n", speed);
    }
    else if (user_input == 'b') {
      if (speed >= 10) {
        speed -= 10;
        printf("Decreasing speed by 10. Current speed: %d\n", speed);
      }
      else {
        printf("You cannot decrease the speed any further.\n");
      }
    }
    else if (user_input == 'c') {
      printf("Hovering in place.\n");
    }
    else if (user_input == 'd') {
      speed = 0;
      printf("Emergency stop initiated. Current speed: %d\n", speed);
    }
    else if (user_input == 'e') {
      printf("Exiting program. Goodbye!\n");
      break;
    }
    else {
      printf("Invalid selection. Please try again.\n");
    }
  }
  
  return 0;
}