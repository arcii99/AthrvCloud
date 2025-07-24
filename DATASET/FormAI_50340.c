//FormAI DATASET v1.0 Category: System boot optimizer ; Style: satisfied
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define number of boot processes to optimize 
#define NUM_BOOT_PROCESSES 1000

// Define maximum boot time in seconds
#define MAX_BOOT_TIME 120

// Define minimum boot time in seconds
#define MIN_BOOT_TIME 30

// Define constant for maximum expected boot time
#define MAX_EXPECTED_BOOT_TIME 60

// Function to generate random boot times
int generateBootTime() {
  return (rand() % (MAX_BOOT_TIME - MIN_BOOT_TIME + 1)) + MIN_BOOT_TIME;
}

int main() {
  int totalBootTime = 0;
  int optimizedBootTime = 0;

  // Seed the random number generator
  srand(time(NULL));

  // Generate random boot times and calculate total boot time
  for (int i = 0; i < NUM_BOOT_PROCESSES; i++) {
    int bootTime = generateBootTime();
    totalBootTime += bootTime;
  }

  // Calculate optimized boot time
  optimizedBootTime = totalBootTime / NUM_BOOT_PROCESSES;

  // Check if optimized boot time is higher than maximum expected boot time
  if (optimizedBootTime > MAX_EXPECTED_BOOT_TIME) {
    printf("Boot time optimization required!\n");

    // Calculate percentage of improvement required
    int percentageImprovement = (optimizedBootTime - MAX_EXPECTED_BOOT_TIME) * 100 / optimizedBootTime;

    // Print optimization message
    printf("Booting processes can be optimized by %d%%.\n", percentageImprovement);
  } else {
    printf("Boot time is optimized! Keep up the good work!\n");
  }

  return 0;
}