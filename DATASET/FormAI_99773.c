//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
  struct sysinfo s_info;
  long long ram_usage;

  while(1) {
    if(sysinfo(&s_info) != 0) {
      printf("Error in reading system information.\n");
      exit(EXIT_FAILURE);
    }

    // Calculate RAM usage
    ram_usage = (s_info.totalram - s_info.freeram) * s_info.mem_unit;

    printf("RAM Usage: %lld bytes\n", ram_usage);
    sleep(1);
  }

  return 0;
}