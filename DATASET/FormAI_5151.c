//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

int main() {
  struct sysinfo info;
  unsigned long used_memory;

  while(1) {
    sysinfo(&info);
    used_memory = (info.totalram - info.freeram);
    printf("Current RAM usage: %lu\n", used_memory);

    // Check if RAM usage is over 75% of total RAM
    if(used_memory > (info.totalram * 0.75)) {
      printf("WARNING: High RAM usage!\n");

      // Kill the top process if it is using a lot of memory
      char command[100];
      sprintf(command, "kill -9 $(ps aux --sort=-%smem | awk 'NR==2{print $2}')");
      system(command);
      printf("Killed top process\n");
    }

    sleep(5);
  }

  return 0;
}