//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CPU_LOAD 100
#define INTERVAL_SEC 3

int main() {
  printf("Hello there! I am your cheerful CPU usage monitor!\n");
  printf("I will measure your computer's CPU usage every %d seconds.\n", INTERVAL_SEC);
  
  while(1) {
    clock_t start = clock();
    
    // Insert code to measure CPU usage here
    
    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    int cpu_load_percentage = (int) ((cpu_time_used / INTERVAL_SEC) * 100);
    
    printf("CPU Usage: %d%%\n", cpu_load_percentage);
    
    if(cpu_load_percentage > MAX_CPU_LOAD) {
      printf("Woah, slow down! Your CPU usage is getting too high!\n");
      // Insert code to handle high CPU load here
    }
    
    sleep(INTERVAL_SEC);
  }
  
  return 0;
}