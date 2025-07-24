//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize random number generator
  srand(time(0));

  // Display message to user
  printf("Greetings traveller! I am the Internet Speed Tester of the King's court. Please wait while I measure your internet speed...\n\n");

  // Simulate internet speed test
  int downloadSpeed = rand() % 100 + 1; // Random number between 1 and 100 Mbps
  int uploadSpeed = rand() % 50 + 1; // Random number between 1 and 50 Mbps
  int latency = rand() % 50 + 1; // Random number between 1 and 50 milliseconds
  int jitter = rand() % 10 + 1; // Random number between 1 and 10 milliseconds

  // Display results to user
  printf("Thy download speed is %d Mbps, upload speed is %d Mbps, latency is %d ms, and jitter is %d ms.\n", downloadSpeed, uploadSpeed, latency, jitter);

  // Determine user's internet quality based on results
  if (downloadSpeed >= 80 && uploadSpeed >= 40 && latency <= 10 && jitter <= 5) {
    printf("Verily, thy internet connection is fit for a knight. Thou may journey the land without interruption.\n");
  } else if (downloadSpeed >= 50 && uploadSpeed >= 25 && latency <= 20 && jitter <= 7) {
    printf("Thy internet connection is satisfactory, traveller. Thou may continue thy quest with minimal interruption.\n");
  } else {
    printf("Alas, thy internet connection is poor. Thou may face challenges on thy journey through the land. Seek ye counsel from the ye olde internet service provider.\n");
  }

  // Farewell message to user
  printf("Farewell, traveller. Safe travels on thy journey.\n");

  return 0;
}