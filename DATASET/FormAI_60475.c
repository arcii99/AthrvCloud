//FormAI DATASET v1.0 Category: Log analysis ; Style: happy
#include <stdio.h>

int main() {
  printf("Welcome to the happy C Log analysis program!\n");

  // Let's pretend we have some log data to analyze
  int logData[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // We can calculate the length of the log data array using sizeof and some math
  int logDataLen = sizeof(logData) / sizeof(int);

  printf("The length of the log data array is %d\n", logDataLen);

  // Let's print out each value in the log data array
  printf("Printing out each value in the log data array...\n");
  for (int i = 0; i < logDataLen; i++) {
    printf("%d ", logData[i]);
  }
  printf("\n");

  // Now let's find the average value of the log data
  int sum = 0;
  for (int i = 0; i < logDataLen; i++) {
    sum += logData[i];
  }
  float average = (float) sum / logDataLen;

  printf("The average value of the log data is %.2f\n", average);

  // Finally, let's find the largest value in the log data
  int max = logData[0];
  for (int i = 1; i < logDataLen; i++) {
    if (logData[i] > max) {
      max = logData[i];
    }
  }

  printf("The largest value in the log data is %d\n", max);

  printf("Thanks for using the happy C Log analysis program!\n");

  return 0;
}