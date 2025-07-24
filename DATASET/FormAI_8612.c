//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: minimalist
#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
  int mb = 1024 * 1024;
  struct sysinfo info;
  sysinfo(&info);
  int total_ram = info.totalram / mb;
  printf("Total RAM: %d MB\n", total_ram);
  while(1) {
    sysinfo(&info);
    int free_ram = info.freeram / mb;
    int used_ram = total_ram - free_ram;
    printf("Used RAM: %d MB, Free RAM: %d MB\n", used_ram, free_ram);
    sleep(1);
  }
  return 0;
}