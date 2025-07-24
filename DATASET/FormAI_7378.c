//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize seed for random number generation
  srand(time(NULL));
  
  // Generate random download speed between 1 and 100 Mbps
  int download_speed = rand() % 100 + 1;
  
  // Generate random upload speed between 1 and 100 Mbps
  int upload_speed = rand() % 100 + 1;
  
  // Print out download and upload speeds
  printf("Your Download Speed: %d Mbps\n", download_speed);
  printf("Your Upload Speed: %d Mbps\n", upload_speed);
  
  // Determine internet quality based on download speed
  if (download_speed >= 75) {
    printf("You have an Excellent internet connection!\n");
  } else if (download_speed >= 50 && download_speed < 75) {
    printf("You have a Good internet connection.\n");
  } else if (download_speed >= 25 && download_speed < 50) {
    printf("Your internet connection is Fair.\n");
  } else {
    printf("Your internet connection is Poor. Please contact your service provider.\n");
  }
  
  return 0;
}