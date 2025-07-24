//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define TOTAL_RAM 1024 // Total RAM of system in MB
#define MIN_THRESHOLD 20 // Minimum threshold in percentage

int main() {
  printf("C RAM Usage Monitor\n");
  
  struct sysinfo mem_info;
  if (sysinfo(&mem_info) != 0) {
    printf("Error: Could not retrieve RAM usage\n");
    return 1;
  }
  
  long total_mem = (mem_info.totalram * mem_info.mem_unit) / (1024 * 1024); // Convert to MB
  long used_mem = ((mem_info.totalram - mem_info.freeram) * mem_info.mem_unit) / (1024 * 1024);
  double mem_usage = ((double) used_mem / (double) total_mem) * 100;
  
  printf("Total RAM: %ld MB\n", total_mem);
  printf("Used RAM: %ld MB\n", used_mem);
  printf("RAM Usage: %.2f%%\n", mem_usage);
  
  if (mem_usage > MIN_THRESHOLD) {
    printf("Warning: RAM usage has exceeded the minimum threshold!\n");
  }
  
  return 0;
}