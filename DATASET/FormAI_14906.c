//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  double download_speed, upload_speed;
  struct timespec start, end;

  printf("Welcome to the Internet Speed Test!\n");
  printf("Checking your download speed...\n");

  // simulate download speed test
  clock_gettime(CLOCK_MONOTONIC, &start);
  for (int i = 0; i < 1000000; i++) {
    int random_bytes = rand() % 1000 + 1;
    int delay = rand() % 10 + 1;
    usleep(delay * 1000);
  }
  clock_gettime(CLOCK_MONOTONIC, &end);

  // calculate download speed
  double elapsed_time = (end.tv_sec - start.tv_sec) * 1e9;
  elapsed_time += (end.tv_nsec - start.tv_nsec);
  download_speed = 1000000 / (elapsed_time / 1e9);
  printf("Your download speed is: %.2f Mbps\n", download_speed);

  printf("Checking your upload speed...\n");

  // simulate upload speed test
  clock_gettime(CLOCK_MONOTONIC, &start);
  for (int i = 0; i < 1000000; i++) {
    int random_bytes = rand() % 1000 + 1;
    int delay = rand() % 10 + 1;
    usleep(delay * 1000);
  }
  clock_gettime(CLOCK_MONOTONIC, &end);

  // calculate upload speed
  elapsed_time = (end.tv_sec - start.tv_sec) * 1e9;
  elapsed_time += (end.tv_nsec - start.tv_nsec);
  upload_speed = 1000000 / (elapsed_time / 1e9);
  printf("Your upload speed is: %.2f Mbps\n", upload_speed);

  return 0;
}