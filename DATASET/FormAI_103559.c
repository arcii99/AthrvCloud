//FormAI DATASET v1.0 Category: Smart home light control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_bulbs = 5;
  int bulb_states[num_bulbs];
  int num_commands = 10;
  int commands[num_commands][2];
  int i;

  srand(time(0));
  
  // Initialize bulb states randomly
  for (i = 0; i < num_bulbs; i++) {
    bulb_states[i] = rand() % 2;
  }

  // Print the initial bulb states
  printf("Initial bulb states: ");
  for (i = 0; i < num_bulbs; i++) {
    printf("%d ", bulb_states[i]);
  }
  printf("\n");

  // Generate commands randomly
  for (i = 0; i < num_commands; i++) {
    commands[i][0] = rand() % 2;  // Command type: 0 for turn off, 1 for turn on
    commands[i][1] = rand() % num_bulbs;  // Index of the bulb to be affected
  }

  // Execute the commands
  for (i = 0; i < num_commands; i++) {
    if (commands[i][0] == 0) {
      bulb_states[commands[i][1]] = 0;
    } else {
      bulb_states[commands[i][1]] = 1;
    }
  }

  // Print the final bulb states
  printf("Final bulb states: ");
  for (i = 0; i < num_bulbs; i++) {
    printf("%d ", bulb_states[i]);
  }
  printf("\n");

  return 0;
}