//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate internet speed test
double testInternetSpeed() {
  // Simulating download speed
  int downloadSpeed = rand() % 101; // Generating random value from 0 to 100
  printf("Downloading file...\n");
  printf("Download speed: %d Mbps\n", downloadSpeed);

  // Simulating upload speed
  int uploadSpeed = rand() % 101; // Generating random value from 0 to 100
  printf("Uploading file...\n");
  printf("Upload speed: %d Mbps\n", uploadSpeed);

  // Calculating average speed
  double averageSpeed = (downloadSpeed + uploadSpeed) / 2.0;
  printf("Average speed: %.2f Mbps\n", averageSpeed);

  return averageSpeed;
}

int main() {
  srand(time(0)); // Initializing random number generator

  printf("Welcome to the Internet Speed Test!\n\n");
  printf("Press any key to start the test...");
  getchar(); // Wait for user to press any key

  double speed = testInternetSpeed();

  // Checking internet speed status
  if (speed >= 75.0) {
    printf("\nCongratulations! Your internet speed is excellent.\n");
  }
  else if (speed >= 50.0) {
    printf("\nYour internet speed is good, but there is room for improvement.\n");
  }
  else if (speed >= 25.0) {
    printf("\nYour internet speed is average, consider upgrading your plan.\n");
  }
  else {
    printf("\nYour internet speed is very slow, please contact your service provider.\n");
  }

  return 0;
}