//FormAI DATASET v1.0 Category: System event logger ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char event[100];
  FILE *fp;
  time_t rawtime;

  fp = fopen("event_log.txt", "a");
  // append mode used for logging multiple events in the same file

  if(fp == NULL) {
    printf("Error: Unable to open file.");
    exit(1);
  }

  printf("Enter the event: ");
  scanf("%[^\n]%*c", event);

  time(&rawtime); // get current system time
  fprintf(fp, "%s - %s\n", ctime(&rawtime), event);

  printf("\nEvent successfully logged! Check event_log.txt\n");

  fclose(fp);
  return 0;
}