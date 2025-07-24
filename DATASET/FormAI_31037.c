//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

void printRAMUsage() {
  struct sysinfo info; // struct to store system information
  if (sysinfo(&info) != 0) { // get system information
    fprintf(stderr, "Error: Could not get system information.\n");
    exit(EXIT_FAILURE);
  }

  long long totalRAM = ((long long)info.totalram * info.mem_unit) / (1024 * 1024); // total RAM in MB
  long long freeRAM = ((long long)info.freeram * info.mem_unit) / (1024 * 1024); // free RAM in MB
  long long usedRAM = totalRAM - freeRAM; // used RAM in MB
  float percentRAMUsed = (float)usedRAM / totalRAM * 100; // percentage of RAM used
  printf("Total RAM: %lld MB, Free RAM: %lld MB, Used RAM: %lld MB, RAM Usage: %.2f%%\n", totalRAM, freeRAM, usedRAM, percentRAMUsed);

  sleep(1); // wait for 1 second
  printRAMUsage(); // call the function recursively
}

int main() {
  printf("Starting RAM usage monitor...\n");
  printRAMUsage(); // call the function to start monitoring RAM usage
  return 0;
}