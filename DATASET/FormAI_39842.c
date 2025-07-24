//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
  printf("Welcome to the Internet Speed Test Application\n");
  printf("This program will measure your internet upload and download speed\n");
  printf("Press any key to continue...");
  
  // Wait for the user to press any key
  getchar();
  
  // Generate random upload and download speeds
  srand(time(0)); 
  int downloadSpeed = rand() % 100;
  int uploadSpeed = rand() % 100;

  printf("Starting download speed test...\n");
  printf("Download speed: %d Mbps\n", downloadSpeed);
  
  // Simulate downloading a file
  int fileSize = 100; // in MB
  int downloadTime = fileSize / downloadSpeed;
  printf("Estimated download time for %d MB file: %d seconds\n", fileSize, downloadTime);
  
  printf("Starting upload speed test...\n");
  printf("Upload speed: %d Mbps\n", uploadSpeed);
  
  // Simulate uploading a file
  int uploadFileSize = 50; // in MB
  int uploadTime = uploadFileSize / uploadSpeed;
  printf("Estimated upload time for %d MB file: %d seconds\n", uploadFileSize, uploadTime);
  
  printf("Thank you for using the Internet Speed Test Application!\n");
  
  return 0;
}