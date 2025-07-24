//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  printf("Ah, Watson, how glad I am to see you! We find ourselves confronted with a most curious case, involving the mysterious usage of C RAM... Let us begin our investigation forthwith.\n\n");
  
  char buf[128];
  FILE *fp;
  int ram_usage;

  while(1) {
    fp = fopen("/proc/meminfo", "r");
    if(fp == NULL) {
      printf("Alack and alas! I cannot access the file /proc/meminfo. Our quest is now at a most unfortunate impasse. Begone, Watson, I shall ponder this matter further in solitude.\n");
      exit(EXIT_FAILURE);
    }

    while( fgets(buf, 128, fp) != NULL ){
        if(strncmp(buf, "MemAvailable:", 13) == 0) {
            sscanf(buf + 13, "%d", &ram_usage);
            break;
        }
    }
    fclose(fp);

    printf("Aha! Our investigation has borne fruit! The current usage of C RAM is %d kilobytes. Perhaps we should check again later on, to see if the situation becomes more... distressing.\n", ram_usage);

    sleep(5); // Let us give the system some breathing space, and wait a bit before continuing our surveillance.
  }
  
  return 0;
}