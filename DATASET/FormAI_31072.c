//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // Declare variables
  int download_speed, upload_speed, ping;
  float total_speed;
  clock_t start, end;
  double time_taken;

  // Get download and upload speed
  printf("Enter download speed in Mbps: ");
  scanf("%d", &download_speed);
  printf("Enter upload speed in Mbps: ");
  scanf("%d", &upload_speed);

  // Get current time
  start = clock();

  // Perform ping test
  system("ping -c 5 google.com");

  // Get end time
  end = clock();

  // Calculate ping time
  time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
  ping = (int) (time_taken * 1000);

  // Calculate total speed
  total_speed = ((float)(download_speed + upload_speed)) / 2;

  // Display results
  printf("\nDownload speed: %d Mbps", download_speed);
  printf("\nUpload speed: %d Mbps", upload_speed);
  printf("\nPing: %d ms", ping);
  printf("\nTotal speed: %.2f Mbps", total_speed);

  return 0;
}