//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int speed = 0;
  srand(time(0)); // initialize random seed
  
  printf("Welcome to the Post-Apocalyptic Internet Speed Test!\n\n");
  
  printf("Press any key to begin the test...\n");
  getchar();
  
  int download_time = rand() % 10 + 1; // random download time between 1 and 10 seconds
  printf("Downloading test file...\n");
  for (int i = 1; i <= download_time; i++) {
    printf("Time elapsed: %d seconds\n", i);
    sleep(1);
  }
  printf("Download complete!\n");
  
  int upload_time = rand() % 10 + 1; // random upload time between 1 and 10 seconds
  printf("Uploading test file...\n");
  for (int i = 1; i <= upload_time; i++) {
    printf("Time elapsed: %d seconds\n", i);
    sleep(1);
  }
  printf("Upload complete!\n");
  
  speed = rand() % 100 + 1; // random internet speed between 1 and 100 Mb/s
  printf("Your internet speed is: %d Mb/s\n", speed);
  
  if (speed < 10) {
    printf("Your internet speed is extremely slow.\n");
  } else if (speed < 25) {
    printf("Your internet speed is slow.\n");
  } else if (speed < 50) {
    printf("Your internet speed is average.\n");
  } else if (speed < 75) {
    printf("Your internet speed is fast.\n");
  } else {
    printf("Your internet speed is blazing fast! Tired of waiting for websites to load? Not anymore.\n");
  }
  
  return 0;
}