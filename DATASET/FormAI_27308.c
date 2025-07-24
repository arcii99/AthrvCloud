//FormAI DATASET v1.0 Category: Robot movement control ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Initializing Robot...\n");
  int battery_level = 100;
  int position_x = 0;
  int position_y = 0;

  printf("Robot initialized!\n\n");

  while(battery_level > 0) {
    printf("Current position: (%d,%d)\n", position_x, position_y);
    printf("Battery level: %d%%\n", battery_level);
    printf("Where do you want me to go? (Up/Down/Left/Right) ");

    char direction[6];
    scanf("%s", direction);

    if(strcmp(direction, "Up") == 0) {
      printf("Moving Up!\n");
      position_y++;
    } else if(strcmp(direction, "Down") == 0) {
      printf("Moving Down!\n");
      position_y--;
    } else if(strcmp(direction, "Left") == 0) {
      printf("Moving Left!\n");
      position_x--;
    } else if(strcmp(direction, "Right") == 0) {
      printf("Moving Right!\n");
      position_x++;
    } else {
      printf("Invalid direction, please try again\n");
      continue;
    }

    battery_level--;
    printf("\n");
  }

  printf("Battery drained! Returning to base...\n");
  printf("Final position: (%d,%d)\n", position_x, position_y);
  printf("Shutting down.\n");

  return 0;
}