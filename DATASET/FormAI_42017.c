//FormAI DATASET v1.0 Category: System event logger ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  FILE *filePointer;
  time_t currentTime;
  char *timestamp;

  // Generate file name based on current date and time
  time(&currentTime);
  timestamp = ctime(&currentTime);
  timestamp[strlen(timestamp) - 1] = '\0';  // Remove extra newline character
  char fileName[26];  // Maximum length of timestamp string is 25
  sprintf(fileName, "Event_Log_%s.txt", timestamp);

  // Open file for writing
  filePointer = fopen(fileName, "w");
  if (filePointer == NULL) {
    printf("Error: Unable to open file!\n");
    exit(1);
  }

  // Prompt user to enter event information
  int eventNumber, eventSeverity;
  printf("Enter event number: ");
  scanf("%d", &eventNumber);
  printf("Enter event severity (1-10): ");
  scanf("%d", &eventSeverity);

  // Write event information to file
  fprintf(filePointer, "Event %d occurred on %s with severity %d.\n", 
          eventNumber, timestamp, eventSeverity);

  // Close file
  fclose(filePointer);

  printf("Event logged successfully!\n");

  return 0;
}