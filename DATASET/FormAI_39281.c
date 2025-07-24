//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: funny
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  printf("Welcome to the CPU destroyer program!\n");
  printf("We are going to make your CPU work really hard today!\n");
  printf("But don't worry, we promise not to break it... much.\n");

  printf("How much CPU usage would you like to see? (0-100%%): ");
  int target_usage;
  scanf("%d", &target_usage);

  while (target_usage < 0 || target_usage > 100)
  {
    printf("Invalid option. Please enter a number between 0 and 100.\n");
    scanf("%d", &target_usage);
  }

  printf("CPU usage target set to %d%%.\n", target_usage);

  printf("Press CTRL+C to stop the program.\n");

  double current_usage;
  while (1)
  {
    current_usage = (double)random() / RAND_MAX * 100;
    printf("Current CPU usage: %.2f%%\n", current_usage);

    if (current_usage > target_usage)
      printf("WARNING: Target usage exceeded! Your CPU is working too hard!\n");

    usleep(500000);
  }

  return 0;
}