//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));  // initialize random seed

  printf("Welcome to the Internet Speed Test Application!\n");
  printf("Press enter to begin testing...\n");
  getchar();

  // simulate download speed test
  printf("Testing Download Speed...\n");
  int download_speed = rand() % 100 + 1;  // generate random download speed
  printf("Download Speed is: %d Mbps\n", download_speed);

  // simulate upload speed test
  printf("Testing Upload Speed...\n");
  int upload_speed = rand() % 100 + 1;  // generate random upload speed
  printf("Upload Speed is: %d Mbps\n", upload_speed);

  // determine internet speed rating
  printf("Determining Internet Speed Rating...\n");
  int speed_rating = (download_speed + upload_speed) / 2;  // calculate average speed
  printf("Your Internet Speed Rating is: %d\n", speed_rating);

  if (speed_rating >= 90) {
    printf("Wow! You have Excellent Internet Speed!\n");
  } else if (speed_rating >= 50) {
    printf("Your Internet Speed is Good.\n");
  } else if (speed_rating >= 30) {
    printf("Your Internet Speed is Average.\n");
  } else {
    printf("Your Internet Speed is Low.\n");
  }

  printf("Thank you for using the Internet Speed Test Application!\n");

  return 0;
}