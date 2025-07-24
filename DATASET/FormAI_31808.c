//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: grateful
// A Grateful C Internet Speed Test Application

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Declare variables
  float speed = 0.0;
  clock_t start, end;
  int time_taken;
  
  printf("Welcome to the Grateful C Internet Speed Test Application!\n");
  printf("Press ENTER to begin the test...");
  getchar();
  printf("Testing download speed...\n");
  
  // Start the clock
  start = clock();

  // Simulate downloading a big file (10 million bytes)
  for (int i = 0; i < 10000000; i++) {
    speed += 1.0;
  }

  // End the clock
  end = clock();

  // Calculate time taken
  time_taken = (int) (end - start) / CLOCKS_PER_SEC;

  // Calculate speed in megabytes per second (MB/s)
  speed = speed / (1024 * 1024 * time_taken);

  // Print results
  printf("Download speed: %.2f MB/s\n", speed);

  // Restart variables for upload test
  speed = 0.0;
  start = clock();

  printf("Testing upload speed...\n");

  // Simulate uploading a big file (10 million bytes)
  for (int i = 0; i < 10000000; i++) {
    speed += 1.0;
  }

  // End the clock
  end = clock();

  // Calculate time taken
  time_taken = (int) (end - start) / CLOCKS_PER_SEC;

  // Calculate speed in megabytes per second (MB/s)
  speed = speed / (1024 * 1024 * time_taken);

  // Print results
  printf("Upload speed: %.2f MB/s\n", speed);

  printf("Thank you for using the Grateful C Internet Speed Test Application!\n");

  return 0;
}