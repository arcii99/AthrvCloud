//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to the CPU usage monitor!\n\n");

  while(1) {
    FILE *fp;
    char path[1024];
    char line[1024];
    float cpu_usage;

    fp = fopen("/proc/stat","r");
    fgets(line,1024,fp);
    char *token = strtok(line," ");
    int count = 0;
    int idle_time = 0;
    while(token != NULL) {
      count++;
      if(count == 5) {
        idle_time = atoi(token);
      }
      token = strtok(NULL," ");
    }
    fclose(fp);

    sleep(1);

    fp = fopen("/proc/stat","r");
    fgets(line,1024,fp);
    token = strtok(line," ");
    count = 0;
    int total_time = 0;
    while(token != NULL) {
      count++;
      if(count != 1) {
        total_time += atoi(token);
      }
      token = strtok(NULL," ");
    }
    fclose(fp);

    cpu_usage = ((1.0 - ((float)idle_time / (float)(total_time))) * 100.0);
    printf("CPU usage: %.2f%%\n",cpu_usage);
  }

  return 0;
}