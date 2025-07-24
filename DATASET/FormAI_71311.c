//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  
  srand(time(NULL));
  
  int download_speed = (rand() % 100) + 1;
  int upload_speed = (rand() % 100) + 1;
  
  printf("Welcome to the Internet Speed Test. \n");
  printf("Your download speed is: %d Mb/s. \n", download_speed);
  printf("Your upload speed is: %d Mb/s. \n", upload_speed);
  
  if(download_speed < 10 || upload_speed < 10) {
    printf("You might want to consider upgrading your internet plan. \n");
  }
  else if(download_speed >= 10 && upload_speed >= 10 && download_speed < 50 && upload_speed < 50) {
    printf("Your internet speed is average. \n");
  }
  else {
    printf("Congratulations! Your internet speed is excellent. \n");
  }
  
  return 0;
}