//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

void monitorRAM() {
  struct sysinfo info;
  sysinfo(&info);
  
  long long totalRAM = info.totalram * info.mem_unit / (1024*1024);
  long long freeRAM = info.freeram * info.mem_unit / (1024*1024);
  long long usedRAM = totalRAM - freeRAM;
  
  printf("\nTotal RAM: %lld MB", totalRAM);
  printf("\nUsed RAM: %lld MB", usedRAM);
  printf("\nFree RAM: %lld MB", freeRAM);
  
  sleep(1); // wait for a second before checking again
  monitorRAM(); // call recursively
}

int main() {
  monitorRAM(); // call the function
  return 0;
}