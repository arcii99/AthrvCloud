//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL));
  int mbps = rand() % 101; // randomly generates internet speed between 0 and 100 mbps
  printf("Welcome to the Internet Speed Test App!\n");
  printf("Your internet speed is a whopping %d mbps! Or is it...\n", mbps);
  printf("Let's make sure your internet speed is up to par.\n");

  printf("Press any key to begin the speed test...\n");
  getchar(); // waits for user to press any key

  int download_speed = rand() % (mbps + 1); // randomly generates download speed between 0 and mbps
  printf("Downloading a test file at %d mbps...\n", download_speed);
  printf("Wow, that was fast! Your internet speed must be amazing.\n");

  printf("Now let's check your upload speed.\n");
  int upload_speed = rand() % (download_speed + 1); // randomly generates upload speed between 0 and download_speed
  printf("Uploading a test file at %d mbps...\n", upload_speed);
  printf("Incredible! Your internet speed is even faster than we thought.\n");

  printf("Congratulations, your internet speed is lightning fast!\n");
  printf("But just in case, let's run another speed test...\n");

  printf("Press any key to begin the second speed test...\n");
  getchar(); // waits for user to press any key

  int second_mbps = rand() % 101; // randomly generates new internet speed between 0 and 100 mbps
  printf("Your internet speed is %d mbps. Let's see if it's consistent...\n", second_mbps);

  if (second_mbps == mbps) {
    printf("Congratulations, your internet speed is consistent!\n");
  }
  else {
    printf("Uh oh, looks like your internet speed is inconsistent. You might want to contact your ISP.\n");
  }

  printf("Thanks for using the Internet Speed Test App! Have a great day and enjoy your lightning fast internet!\n");

  return 0;
}