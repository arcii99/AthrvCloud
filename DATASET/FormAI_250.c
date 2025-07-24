//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_DRONE_COUNT 10
#define MAX_COMMAND_LENGTH 100

char droneCommands[MAX_DRONE_COUNT][MAX_COMMAND_LENGTH];
int droneCount;

void readCommands()
{
  printf("Enter the number of drones (max. %d):\n", MAX_DRONE_COUNT);
  scanf("%d", &droneCount);

  if (droneCount > MAX_DRONE_COUNT) {
    printf("Exceeded maximum drone count. Please try again.\n");
    exit(EXIT_FAILURE);
  }

  printf("Enter commands for each drone:\n");

  for (int i = 1; i <= droneCount; ++i) {
    printf("Drone %d: ", i);
    scanf("%s", droneCommands[i - 1]);
  }
}

int main()
{
  readCommands();

  printf("Drone Commands:\n");
  for (int i = 0; i < droneCount; ++i) {
    printf("Drone %d: %s\n", i + 1, droneCommands[i]);
  }

  return 0;
}