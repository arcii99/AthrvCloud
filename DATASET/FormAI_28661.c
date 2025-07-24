//FormAI DATASET v1.0 Category: System boot optimizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  printf("Welcome to the Boot Optimizer 9000!\n");
  printf("Preparing to optimize...Please standby\n");

  // Initializing variables
  int optimization_percentage = 0;
  char optimization_level[10];

  // Getting the optimization level from the user
  printf("Please enter your desired optimization level (low/medium/high): ");
  scanf("%s", optimization_level);

  // Checking if the user input is valid
  if(strcmp(optimization_level, "low") == 0) {
      optimization_percentage = 20;
  } else if(strcmp(optimization_level, "medium") == 0) {
      optimization_percentage = 50;
  } else if(strcmp(optimization_level, "high") == 0) {
      optimization_percentage = 90;
  } else {
      printf("Invalid input! Defaulting to low optimization.\n");
  }

  // Showing the user the optimization percentage
  printf("Optimizing...please wait\n");
  printf("Optimization: %d percent optimized\n", optimization_percentage);

  // Randomizing optimization levels
  int i;
  for(i = 0; i < optimization_percentage; ++i) {
      int random_level = (rand() % 3) + 1;
      if(random_level == 1) {
          printf("Compiling... %d%%\n", (i / optimization_percentage) * 100);
      } else if(random_level == 2) {
          printf("Cleaning up system junk... %d%%\n", (i / optimization_percentage) * 100);
      } else if(random_level == 3) {
          printf("Speeding up boot process... %d%%\n", (i / optimization_percentage) * 100);
      }
  }

  printf("Optimization complete! Your system is now ready to go\n");

  return 0;
}