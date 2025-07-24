//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int downloadSpeed, uploadSpeed;

  // Seed the random number generator
  srand(time(0));

  // Generate random download and upload speeds between 1 and 100 Mbps
  downloadSpeed = rand() % 100 + 1;
  uploadSpeed = rand() % 100 + 1;

  // Display the results to the user
  printf("Internet Speed Test Results:\n");
  printf("Download Speed: %d Mbps\n", downloadSpeed);
  printf("Upload Speed: %d Mbps\n", uploadSpeed);

  // Determine the internet connection status based on download speed
  if (downloadSpeed >= 50) {
    printf("Connection Status: Excellent\n");
  } else if (downloadSpeed >= 20 && downloadSpeed < 50) {
    printf("Connection Status: Good\n");
  } else if (downloadSpeed >= 10 && downloadSpeed < 20) {
    printf("Connection Status: Fair\n");
  } else {
    printf("Connection Status: Poor\n");
  }

  return 0;
}