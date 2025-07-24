//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main() {
  struct sysinfo sys_info;
  while(1) {
    if(sysinfo(&sys_info) != 0) {
      printf("Error getting system info.\n");
      exit(1);
    }
    long long total_ram = sys_info.totalram;
    long long free_ram = sys_info.freeram;
    long long used_ram = total_ram - free_ram;
    double usage_per = ((double)used_ram/total_ram) * 100;
    printf("Total RAM: %lld MB\n", total_ram/1024/1024);
    printf("Used RAM: %lld MB\n", used_ram/1024/1024);
    printf("Free RAM: %lld MB\n", free_ram/1024/1024);
    printf("Usage: %.2lf%%\n", usage_per);
    sleep(1); 
  }
  return 0;
}