//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int bytes_sent, bytes_received, download_speed, upload_speed;
  
  printf("Welcome to the Internet speed test!\n");
  printf("Please enter the number of bytes sent: ");
  scanf("%d", &bytes_sent);
  
  printf("Please enter the number of bytes received: ");
  scanf("%d", &bytes_received);
  
  printf("Calculating download speed...\n");
  download_speed = bytes_received / 1024; // convert bytes to kilobytes
  printf("Download speed: %d kb/s\n", download_speed);
  
  printf("Calculating upload speed...\n");
  upload_speed = bytes_sent / 1024; // convert bytes to kilobytes
  printf("Upload speed: %d kb/s\n", upload_speed);
  
  return 0;
}