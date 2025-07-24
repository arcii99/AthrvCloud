//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed random number generator
  
  int downloadSpeed = rand() % 100 + 1; // Generate random number between 1 and 100
  int uploadSpeed = rand() % 100 + 1; // Generate random number between 1 and 100
  
  printf("Welcome to the C Internet Speed Test Application!\n");
  printf("Performing download speed test...\n");
  
  // Simulate download speed test by printing dots with increasing delay between each dot
  for(int i = 0; i < downloadSpeed; i++) {
    printf(".");
    fflush(stdout); // Flush output buffer to ensure dots are printed one by one
    for(int j = 0; j < 100000000; j++);
  }
  
  printf("\nDownload speed test complete! Your download speed is %d Mbps.\n", downloadSpeed);
  printf("\nPerforming upload speed test...\n");
  
  // Simulate upload speed test by printing asterisks with increasing delay between each asterisk
  for(int i = 0; i < uploadSpeed; i++) {
    printf("*");
    fflush(stdout); // Flush output buffer to ensure asterisks are printed one by one
    for(int j = 0; j < 100000000; j++);
  }
  
  printf("\nUpload speed test complete! Your upload speed is %d Mbps.\n", uploadSpeed);
  printf("\nThank you for using the C Internet Speed Test Application.\n");
  
  return 0;
}