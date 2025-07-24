//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/resource.h>

int count = 0;
float prev_cpu_time = 0.0;

void handle_signal(int signal){
  printf("CPU Usage:\t%f%%\n",prev_cpu_time);
  count = 0;
  prev_cpu_time = 0.0;
}

float calculate_cpu_time(){
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  float cpu_time = (usage.ru_utime.tv_sec + usage.ru_utime.tv_usec/1000000.0) +
        (usage.ru_stime.tv_sec + usage.ru_stime.tv_usec/1000000.0);
  return cpu_time;
}

int main(){
  float cpu_time;
  signal(SIGINT, handle_signal);
  while(1){
    sleep(1);
    count++;

    if(count == 10){
      count = 0;
      cpu_time = calculate_cpu_time();
      printf("CPU Usage:\t%f%%\n",(cpu_time-prev_cpu_time)*100.0/sysconf(_SC_CLK_TCK));
      prev_cpu_time = cpu_time;
    }
  }
  return 0;
}