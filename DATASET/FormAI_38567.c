//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MAX_LEN 128

int main() {
  struct sysinfo memInfo;
  long long totalRAM, freeRAM, usedRAM;

  while(1) {
    // Get system RAM info
    sysinfo(&memInfo);
    totalRAM = memInfo.totalram / 1024;
    freeRAM = memInfo.freeram / 1024;
    usedRAM = totalRAM - freeRAM;
  
    // Create status messages
    char totalRAMMessage[MAX_LEN];
    char freeRAMMessage[MAX_LEN];
    char usedRAMMessage[MAX_LEN];
  
    sprintf(totalRAMMessage, "Total RAM: %lld kB", totalRAM);
    sprintf(freeRAMMessage, "Free RAM: %lld kB", freeRAM);
    sprintf(usedRAMMessage, "Used RAM: %lld kB", usedRAM);

    // Print status messages
    printf("***************************************\n");
    printf("*                                     *\n");
    printf("*      C RAM Usage Monitor Example    *\n");
    printf("*                                     *\n");
    printf("***************************************\n\n");

    printf("%s\n", totalRAMMessage);
    printf("%s\n", freeRAMMessage);
    printf("%s\n\n", usedRAMMessage);
    
    // Sleep for 5 seconds
    sleep(5);
    // Clear console
    system("clear");
  }

  return 0;
}