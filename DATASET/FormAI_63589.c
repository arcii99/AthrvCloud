//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: genious
#include <stdio.h>
#define KB 1024
#define MB 1048576
#define GB 1073741824

int main() {
  long int fileSize = 0;
  double downloadSpeed = 0.0;
  double timeTaken = 0.0;
  char choice = 'N';

  do {
    printf("Please enter the size of the file to test (in GB):\n");
    scanf("%ld", &fileSize);

    printf("Please enter the download speed (in Mbps):\n");
    scanf("%lf", &downloadSpeed);

    // Convert download speed from Mbps to MBps
    downloadSpeed = downloadSpeed / 8;

    timeTaken = ((fileSize * GB) / (downloadSpeed * MB));

    printf("The time taken to download a %ld GB file at %.2lf Mbps is %.2lf seconds\n\n", fileSize, (downloadSpeed*8), timeTaken);

    printf("Do you want to run the test again? (Y/N)\n");
    scanf(" %c", &choice);

    while (getchar() != '\n'); // Flush input buffer

  } while (choice == 'y' || choice == 'Y');

  printf("Goodbye!");

  return 0;
}