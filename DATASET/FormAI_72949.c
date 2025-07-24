//FormAI DATASET v1.0 Category: System event logger ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Romeo and Juliet style C System event logger

int main() {
  printf("Enter thy name, fair developer: ");
  char name[50];
  scanf("%s", name);
  printf("Good morrow, %s! Thou art about to witness the events of this system be logged.\n", name);
  printf("But waiteth! Should we not swear an oath of secrecy, that we shall not disclose the events we record?\n");
  printf("Enter 'Yes' to swear the oath of secrecy: ");
  char oath[10];
  scanf("%s", oath);
  
  if (strcmp(oath, "Yes") == 0) {
    printf("Aye, our lips shall be sealed. Let the logging commence!\n");
    time_t now;
    time(&now);
    FILE *fp = fopen("system_log.txt", "a");
    fprintf(fp, "=== System events log for %s ===\n", ctime(&now));
    
    int count = 0;
    while (count < 10) {
      printf("Type in an event to log (#%d of 10): ", count+1);
      char event[100];
      scanf(" %[^\n]", event);
      fprintf(fp, "%s\n", event);
      count++;
    }
    
    printf("The events have been logged. Let us meet again, %s.\nFarewell!\n", name);
    fclose(fp);
    
  } else {
    printf("Then let us part ways. Goodbye, %s.\n", name);
  }
  
  return 0;
}