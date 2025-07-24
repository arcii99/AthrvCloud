//FormAI DATASET v1.0 Category: Robot movement control ; Style: funny
#include <stdio.h>

int main() {
  printf("Hello there! I'm a C Robot and I'm ready to move around!\n");
  printf("Enter your move command: ");

  char move;
  int x = 0;
  int y = 0;
  int is_robot_on = 1;

  while (is_robot_on) {
    scanf("%c", &move);
    switch(move) {
      case 'w':
        printf("Moving forward!\n");
        y += 1;
        break;
      case 'a':
        printf("Turning left!\n");
        x -= 1;
        break;
      case 's':
        printf("Moving backward!\n");
        y -= 1;
        break;
      case 'd':
        printf("Turning right!\n");
        x += 1;
        break;
      case 'q':
        printf("Quitting movement program!\n");
        is_robot_on = 0;
        break;
      default:
        printf("Invalid command!\n");
        break;
    }
    printf("x: %d, y: %d\n", x, y);
    printf("Enter your move command: ");
  }
  printf("Goodbye!");
  return 0;
}