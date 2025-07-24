//FormAI DATASET v1.0 Category: System boot optimizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp;
  char buffer[1024];
  int bootTime;
  int cpuLoad;
  int freeMem;
  int optMem;
  
  fp = fopen("/proc/stat", "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening /proc/stat\n");
    exit(1);
  }
  
  fgets(buffer, sizeof(buffer), fp);
  sscanf(buffer, "cpu %*d %*d %*d %*d %*d %*d %*d %*d %*d %d", &cpuLoad);
  
  fclose(fp);
  
  fp = fopen("/proc/meminfo", "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening /proc/meminfo\n");
    exit(1);
  }
  
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    if (strncmp(buffer, "MemAvailable:", 13) == 0) {
      sscanf(buffer + 13, "%d", &freeMem);
    } else if (strncmp(buffer, "MemTotal:", 9) == 0) {
      sscanf(buffer + 9, "%d", &optMem);
    }
  }
  
  fclose(fp);
  
  bootTime = (int)time(NULL);
  printf("System boot time: %d\n", bootTime);
  printf("Current CPU load: %d\n", cpuLoad);
  printf("Free memory: %d kB\n", freeMem);
  printf("Optimal memory: %d kB\n", optMem);
  
  return 0;
}