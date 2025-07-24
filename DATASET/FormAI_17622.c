//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: portable
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
  int mb = 50; // Define the number of megabytes to download
  int download_speed; // User's internet download speed, in megabits per second
  int download_time; // Time it takes to download the given number of megabytes
  int i;

  printf("Welcome to the Internet Speed Test Application.\n");
  printf("Please enter your internet download speed (in megabits per second): ");
  scanf("%d", &download_speed);

  // Calculate the time it takes to download the given number of megabytes
  download_time = (int) ((double) (mb * 8) / download_speed);

  printf("Starting download of %d megabytes...\n", mb);

  // Simulate downloading the given number of megabytes
  for (i = 0; i < mb; i++) {
    int random_download_time = (rand() % 3) + 1; // Generate a random download time between 1 and 3 seconds
    printf("Downloaded 1 Megabyte (%d/%d)\n", i+1, mb);
    sleep(random_download_time); // Simulate download time
  }

  printf("Download complete!\n");
  printf("Your internet speed is %d megabits per second.\n", download_speed);
  printf("It took %d seconds to download %d megabytes.\n", download_time, mb);

  return 0;
}