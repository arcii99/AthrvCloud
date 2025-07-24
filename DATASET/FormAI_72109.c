//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  printf("Welcome to the Internet Speed Test Application\n\n");
  
  int downloadSpeed, uploadSpeed; // create variables to hold the internet speed data
  
  srand(time(0)); // use the time as a seed for the random number generator
  
  downloadSpeed = rand() % 101; // generate a random download speed between 0 and 100 Mbps
  uploadSpeed = rand() % 101; // generate a random upload speed between 0 and 100 Mbps
  
  printf("Testing your internet speed...\n\n");
  
  printf("Download speed: %d Mbps\n", downloadSpeed);
  printf("Upload speed: %d Mbps\n\n", uploadSpeed);
  
  if (downloadSpeed >= 50 && uploadSpeed >= 50) { // check if the internet speed is fast enough
    printf("Your internet speed is FAST! You can stream videos, play games, and browse the web without any problems.\n");
  } else if ((downloadSpeed >= 25 && downloadSpeed < 50) || (uploadSpeed >= 25 && uploadSpeed < 50)) {
    printf("Your internet speed is OKAY, but it might not be fast enough for some activities like streaming HD videos or playing online games.\n");
  } else {
    printf("Your internet speed is SLOW! You might experience problems while streaming, gaming, or browsing the web. Consider upgrading your internet plan.\n");
  }
  
  return 0;
  
}