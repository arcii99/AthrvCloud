//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: careful
#include <stdio.h>
#include <unistd.h>

int main() {
  FILE* fp;
  char buffer[1024];
  int cpu, idle;
  
  while(1) {
    fp = fopen("/proc/stat", "r");
    if(fp == NULL) {
      printf("Failed to open file.");
      return 1;
    }
    
    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "%*s %d %*d %d", &cpu, &idle);
    fclose(fp);
    
    printf("CPU usage: %d%%\n", (100 * (cpu - idle)) / cpu);
    sleep(1);
  }
  
  return 0;
}