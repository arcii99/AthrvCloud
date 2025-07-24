//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Internet Speed Test Application!\n\n");
  printf("This program will simulate a download speed test by generating random bytes and measuring the time it takes to download.\n\n");

  // Prompt user to enter speed in Mbps
  int internetSpeed, downloadSpeed;
  printf("Please enter your internet speed in Mbps: ");
  scanf("%d", &internetSpeed);
  printf("\n");

  // Generate random bytes for download test (between 1MB and 10MB)
  int maxBytes = 10000000;
  int minBytes = 1000000;
  int totalBytes = rand() % (maxBytes - minBytes + 1) + minBytes;
  printf("Generating random bytes for download test...\n");
  int bytesDownloaded = 0;
  clock_t startTime = clock();

  while (bytesDownloaded < totalBytes) {
    // Generate random byte
    char byte = rand() % 256;
    bytesDownloaded++;

    // Simulate download by delaying for internet speed in ms
    int downloadDelay = 1000 / internetSpeed;
    int i;
    for (i = 0; i < downloadDelay; i++) {
      // Delay
    }
  }

  clock_t endTime = clock();

  // Calculate download speed in Mbps
  double downloadTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
  downloadSpeed = (int)((double)totalBytes / downloadTime / 125000);
  printf("Download speed is %d Mbps\n", downloadSpeed);

  return 0;
}