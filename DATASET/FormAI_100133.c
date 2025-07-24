//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main(int argc, char** argv) {
  int i;
  for(i = 0; i < 10; i++) {
    struct sysinfo info;
    sysinfo(&info);
    //calculate percentage CPU usage
    unsigned long long total_time = info.totalram - info.freeram;
    unsigned long long seconds_since_boot = info.uptime;
    unsigned long long cpu_usage = total_time / seconds_since_boot;
    printf("CPU usage: %llu%%\n", cpu_usage);
    if(i % 2 == 0) {
      printf("==============================\n");
    }
    else {
      printf("------------------------------\n");
    }
    sleep(1);
  }
  return 0;
}