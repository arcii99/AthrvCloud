//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MILLION 1000000

int main(int argc, char *argv[]) {
  struct sysinfo info; // Sysinfo struct
  long long usage;
  
  while(1) {
    sysinfo(&info); // Get RAM information
    usage = (info.totalram - info.freeram) * info.mem_unit; // Calculate used RAM in bytes
    printf("RAM Usage: %lld MB\n", usage/MILLION); // Print RAM usage in MB
    sleep(5); // Sleep for 5 seconds
  }

  return 0;
}