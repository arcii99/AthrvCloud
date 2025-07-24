//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char url[50];
  int speed, i;

  printf("Welcome to the Internet Speed Test!\n");
  printf("Please enter the URL you wish to test:\n");

  scanf("%s", url);

  printf("Testing speed for %s...\n", url);

  // Generate random speed
  srand(time(NULL));
  speed = rand() % 101;

  // Simulate testing speed for 5 seconds
  for (i = 0; i < 5; i++) {
    printf("Testing speed...%d%%\n", speed);
    sleep(1);
    speed = rand() % 101;
  }

  // Display the final speed
  printf("Testing complete! Your speed is: %d Mbps\n", speed);

  return 0;
}