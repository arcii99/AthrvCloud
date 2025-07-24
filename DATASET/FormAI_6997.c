//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Initializing the random number generator

  int download_speed = (rand() % 101); // Generating a random download speed between 0 and 100 Mbps
  int upload_speed = (rand() % 101); // Generating a random upload speed between 0 and 100 Mbps

  printf("Your download speed is %d Mbps and your upload speed is %d Mbps.\n", download_speed, upload_speed);

  if (download_speed <= 10) {
    printf("Your download speed is very slow. Consider upgrading your internet plan.\n");
  } else if (download_speed <= 25) {
    printf("Your download speed is slow. You may experience buffering while streaming videos.\n");
  } else if (download_speed <= 50) {
    printf("Your download speed is average. You should be able to stream videos without buffering.\n");
  } else if (download_speed <= 100) {
    printf("Your download speed is fast. You should be able to download large files quickly.\n");
  } else {
    printf("Your download speed is extremely fast. You have an amazing internet connection!\n");
  }

  if (upload_speed <= 10) {
    printf("Your upload speed is very slow. Consider upgrading your internet plan.\n");
  } else if (upload_speed <= 25) {
    printf("Your upload speed is slow. You may experience slow upload times.\n");
  } else if (upload_speed <= 50) {
    printf("Your upload speed is average. You should be able to upload files without much delay.\n");
  } else if (upload_speed <= 100) {
    printf("Your upload speed is fast. You should be able to upload large files quickly.\n");
  } else {
    printf("Your upload speed is extremely fast. You have an amazing internet connection!\n");
  }

  return 0;
}