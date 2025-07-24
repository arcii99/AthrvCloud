//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  char command[100];
  char buffer[1024];
  double cpu;
  long int cpuTime[2][2];

  strcpy(command, "cat /proc/stat | grep 'cpu '");
  FILE* fp = popen(command, "r");
  if (fp == NULL) {
    printf("Failed to run command\n");
    exit(1);
  }

  fgets(buffer, sizeof(buffer)-1, fp);
  pclose(fp);

  sscanf(buffer, "%*s %ld %ld %ld %ld %ld %ld %ld %ld",
         &cpuTime[0][0], &cpuTime[0][1], &cpuTime[0][2], &cpuTime[0][3],
         &cpuTime[0][4], &cpuTime[0][5], &cpuTime[0][6], &cpuTime[0][7]);

  while (1) {
    fp = popen(command, "r");
    if (fp == NULL) {
      printf("Failed to run command\n");
      exit(1);
    }

    fgets(buffer, sizeof(buffer)-1, fp);
    pclose(fp);

    sscanf(buffer, "%*s %ld %ld %ld %ld %ld %ld %ld %ld",
           &cpuTime[1][0], &cpuTime[1][1], &cpuTime[1][2], &cpuTime[1][3],
           &cpuTime[1][4], &cpuTime[1][5], &cpuTime[1][6], &cpuTime[1][7]);

    double total = (cpuTime[1][0] + cpuTime[1][1] + cpuTime[1][2] + cpuTime[1][3]
                     + cpuTime[1][4] + cpuTime[1][5] + cpuTime[1][6] + cpuTime[1][7])
                   - (cpuTime[0][0] + cpuTime[0][1] + cpuTime[0][2] + cpuTime[0][3]
                      + cpuTime[0][4] + cpuTime[0][5] + cpuTime[0][6] + cpuTime[0][7]);

    double idle = (cpuTime[1][3] - cpuTime[0][3]);

    cpu = (total - idle) / total * 100;

    printf("\033[0;33m");
    printf("\nCPU Usage: \033[0;31m%.2lf%%\033[0;33m\n", cpu);
    printf("\033[0m");

    sleep(1);

    cpuTime[0][0] = cpuTime[1][0];
    cpuTime[0][1] = cpuTime[1][1];
    cpuTime[0][2] = cpuTime[1][2];
    cpuTime[0][3] = cpuTime[1][3];
    cpuTime[0][4] = cpuTime[1][4];
    cpuTime[0][5] = cpuTime[1][5];
    cpuTime[0][6] = cpuTime[1][6];
    cpuTime[0][7] = cpuTime[1][7];
  }

  return 0;
}