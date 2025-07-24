//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: protected
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CPU_USAGE 100
#define INTERVAL 1
#define MAX_SIZE 1024

int main(void) {
  int cpu_percentage;
  clock_t start, end;
  double cpu_time_used;
  char command[MAX_SIZE] = "";
  char output[MAX_SIZE] = "";

  while(1) {
    start = clock();
    sprintf(command, "ps -A -o %%cpu | awk '{s+=$1} END {print s}'");
    FILE *pipe = popen(command, "r");
    if(!pipe) {
      printf("Error: Failed to open pipe.\n");
      exit(1);
    }
    fgets(output, MAX_SIZE, pipe);
    cpu_percentage = atoi(output);
    end = clock();
    fclose(pipe);
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nCurrent CPU Usage: %d%%\n", cpu_percentage);
    printf("Time taken for CPU usage calculation: %f\n", cpu_time_used); 

    if(cpu_percentage > MAX_CPU_USAGE) {
      printf("CPU usage crossed limit. Stopping program now!\n");
      exit(0);
    }
    sleep(INTERVAL);
  }

  return 0;
}