//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // to generate random numbers

  int internet_speed = rand() % 101; // generating random internet speed between 0 to 100 mbps
  int download_size = rand() % 1001; // generating random download size between 0 to 1000 MB

  printf("Welcome to the Internet Speed Test Application!\n\n");
  printf("Your current internet speed is: %d Mbps\n", internet_speed);
  printf("We will now test how long it takes to download a %d MB file...\n\n", download_size);

  double download_speed = (double)internet_speed/8; // converting internet speed from mbps to MB/s
  int download_time = (int)((double)download_size/download_speed); // calculating download time in seconds

  printf("Your download speed is: %.2lf MB/s\n", download_speed);
  printf("It will take %d seconds to download a file of %d MB.\n\n", download_time, download_size);

  printf("Thank you for using the Internet Speed Test Application!\n");

  return 0;
}