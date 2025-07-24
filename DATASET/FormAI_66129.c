//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MEMINFO "/proc/meminfo"

int main() {
  FILE *file = fopen(MEMINFO, "r");
  if (!file) {
    printf("Error: Cannot open %s\n", MEMINFO);
    return 1;
  }
  
  char line[256];
  long total_mem;
  long free_mem;
  while (fgets(line, 256, file)) {
    if (strncmp(line, "MemTotal:", 9) == 0) {
      sscanf(line + 9, "%ld", &total_mem);
    }
    if (strncmp(line, "MemFree:", 8) == 0) {
      sscanf(line + 8, "%ld", &free_mem);
    }
  }
  
  fclose(file);
  
  printf("Total memory: %ld kB\n", total_mem);
  printf("Free memory: %ld kB\n", free_mem);
  
  float ram_usage = ((float)(total_mem - free_mem) / total_mem) * 100;
  printf("RAM usage: %.2f%%\n", ram_usage);

  return 0;
}