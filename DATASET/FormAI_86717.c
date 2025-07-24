//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
  printf("Welcome to the Internet Speed Test App!\n");

  // Generate random download and upload speeds between 1 and 100
  srand(time(0));
  int download_speed = rand() % 100 + 1;
  int upload_speed = rand() % 100 + 1;

  // Simulate speed test
  printf("Testing download speed...\n");
  sleep(2);
  printf("Download speed: %d Mbps\n", download_speed);

  printf("Testing upload speed...\n");
  sleep(2);
  printf("Upload speed: %d Mbps\n", upload_speed);

  // Determine if speed is fast or slow
  if (download_speed > 50 && upload_speed > 50) {
    printf("Wow, your internet speeds are blazing fast! 🚀\n");
  } else if (download_speed < 10 && upload_speed < 10) {
    printf("Uh oh, looks like your internet is crawling... 🐌\n");
  } else {
    printf("Not bad, but could be better! 💻\n");
  }

  return 0;
}