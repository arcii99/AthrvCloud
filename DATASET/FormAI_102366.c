//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
  srand(time(NULL));
  int timeOut, timeIn;
  timeOut = rand() % 6+1;
  timeIn = rand() % 6+1;

  printf("Initializing Traffic Light Controller...\n");

  while (1) // Loop forever
  {
    printf("\nRED Light: Stop\n");
    printf("YELLOW Light: Get Ready\n");
    printf("GREEN Light: Go\n\n");

    printf("Cars going out of the city can pass for %d seconds...\n", timeOut);
    for (int i = timeOut; i > 0; --i) {
      printf("%d... ", i);
      sleep(1);
    }

    printf("\nCars coming into the city can pass for %d seconds...\n", timeIn);
    for (int i = timeIn; i > 0; --i) {
      printf("%d... ", i);
      sleep(1);
    }
  }

  return 0;
}