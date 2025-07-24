//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int download_speed, upload_speed;
  srand(time(NULL)); // Seed for random number generation

  printf("Welcome to Internet Speed Test Application\n");

  // Simulating download speed test
  printf("Testing download speed...\n");
  download_speed = rand() % 100 + 1; // Generating random integer between 1 to 100
  printf("Download speed is %d Mbps\n", download_speed);

  // Simulating upload speed test
  printf("Testing upload speed...\n");
  upload_speed = rand() % 100 + 1; // Generating random integer between 1 to 100
  printf("Upload speed is %d Mbps\n", upload_speed);

  // Determining internet speed status based on download speed
  printf("Your internet speed status is: ");
  if (download_speed > 80) {
    printf("Excellent\n");
  } else if (download_speed > 60) {
    printf("Good\n");
  } else if (download_speed > 40) {
    printf("Average\n");
  } else {
    printf("Poor\n");
  }

  return 0;
}