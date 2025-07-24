//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
  // Declare variables
  int download_speed, upload_speed;
  float latency;

  // Generate random numbers for speed and latency
  srand(time(NULL));
  download_speed = rand() % 100 + 1;
  upload_speed = rand() % 100 + 1;
  latency = ((float)rand()/(float)(RAND_MAX)) * 100;

  // Output results to user
  printf("Welcome to the Internet Speed Test Application!\n\n");
  printf("Testing your download speed...\n");
  printf("Download speed: %d Mbps\n", download_speed);
  sleep(1);
  printf("Testing your upload speed...\n");
  printf("Upload speed: %d Mbps\n", upload_speed);
  sleep(1);
  printf("Testing your latency...\n");
  printf("Latency: %.2f ms\n", latency);

  return 0;
}