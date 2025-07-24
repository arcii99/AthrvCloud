//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: funny
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int count = 0;
  printf("Welcome to the CPU Usage Monitor!\n");
  printf("Press Ctrl+C to quit the program.\n\n");

  while(1) {
      FILE* cpuFile = fopen("/proc/stat", "r");
      char line[256];
      double user, nice, system, idle;
      fscanf(cpuFile, "%s %lf %lf %lf %lf", line, &user, &nice, &system, &idle);

      printf("Current CPU Usage: %.2lf%%\n", (user + nice + system) * 100 / (user + nice + system + idle));
      fclose(cpuFile);

      count++;
      if (count == 10) {
          printf("\nWow, your computer is really working hard today! Maybe you should give it a break.\n");
          count = 0;
      }

      sleep(1);
   }

   return 0;
}