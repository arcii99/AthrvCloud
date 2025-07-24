//FormAI DATASET v1.0 Category: System boot optimizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // Seed random number generator
  srand(time(NULL));

  // Generate a random number between 1 and 10
  int bootTime = rand() % 10 + 1;

  // Print booting message
  printf("System is booting...\n");

  // Start boot optimizer
  printf("Running boot optimizer...\n");
  for (int i = 0; i < bootTime; i++) {
    // Simulate boot optimizer process
    int optimizerProgress = (i * 100) / bootTime;
    printf("Optimizing system boot: %d%%\n", optimizerProgress);

    // Delay for a random amount of time
    int delayTime = rand() % 3 + 1;
    printf("Estimated time remaining: %d seconds\n", delayTime);
    sleep(delayTime);
  }

  // System has finished booting
  printf("System is now optimized and ready to use.\n");
  
  return 0;
}