//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int speed;
  srand(time(NULL));

  printf("Welcome to the Shocked Internet Speed Tester!\n");
  printf("This program will test your download speed and compare it to the average internet speed.\n");
  printf("Please enter your download speed in Mbps: ");
  scanf("%d", &speed);

  if(speed < 0) {
    printf("\nOh no! Something went wrong. Please try again.\n");
    return 0;
  }

  printf("\nTesting your download speed...\n");

  int random_time = rand() % (200 - 50 + 1) + 50; // generate a random time for the speed test
  printf("Estimated time left: %d seconds\n", random_time);

  int download_speed = 0;
  for(int i = 0; i < random_time; i++) {
    // simulate download speed by adding random numbers
    download_speed += rand() % 10;
    printf("Download speed: %d Mbps\n", download_speed);
  }

  printf("\nTest complete!\n");

  int average_speed = 23; // set the average internet speed
  printf("The average internet speed is %d Mbps\n", average_speed);

  if(download_speed < average_speed) {
    printf("Oh no! Your internet is slower than average.\n");
  } else if(download_speed == average_speed) {
    printf("Your internet speed is average.\n");
  } else {
    printf("Congratulations! Your internet is faster than average.\n");
  }

  return 0;
}