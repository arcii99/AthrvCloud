//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Internet Speed Test!\n");

  printf("\nPlease wait while we test your download speed...");

  // simulate download speed test by generating a random number between 1 and 100 (Mbps)
  srand(time(NULL));
  int downloadSpeed = rand() % 100 + 1;
  printf("\nYour download speed is %d Mbps!", downloadSpeed);

  printf("\n\nNow, let's test your upload speed...");

  // simulate upload speed test by generating a random number between 1 and 50 (Mbps)
  int uploadSpeed = rand() % 50 + 1;
  printf("\nYour upload speed is %d Mbps!", uploadSpeed);

  printf("\n\nCongratulations! Your internet speed is faster than a cheetah!");

  return 0;
}