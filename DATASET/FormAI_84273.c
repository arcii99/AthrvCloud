//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DELAY 1000000
#define THRESHOLD 80 // percentage threshold for high CPU usage

int main() {
  int i = 0;
  time_t start_time, end_time;
  double diff_time;
  char instruction[256];
  int cpu_load, total_load = 0, num_samples = 0;

  printf("Starting CPU usage monitor...\n");

  while(1) {
    // Get current CPU load using a random number generator
    srand(time(NULL));
    cpu_load = rand() % 100;

    total_load += cpu_load;
    num_samples++;

    // Check if CPU usage has exceeded threshold
    if(cpu_load >= THRESHOLD) {
      printf("High CPU usage detected! Load: %d%%\n", cpu_load);

      // Stop the program and ask user for instructions
      printf("Enter 's' to stop monitoring, or any other key to continue: ");
      scanf("%s", instruction);

      if(instruction[0] == 's') {
        printf("Stopping CPU usage monitor...\n");
        break;
      }
    }

    // Wait for DELAY microseconds before checking again
    usleep(DELAY);
  }

  // Print average CPU usage for the session
  printf("Session average CPU usage: %d%%\n", total_load / num_samples);

  return 0;
}