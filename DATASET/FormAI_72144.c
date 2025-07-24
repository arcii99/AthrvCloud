//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_CPU_USAGE 100 // Maximum CPU usage percentage

int main(void) {
  float cpu, prev_cpu = 0;
  int sleep_time = 1; // Sleep time in seconds
  clock_t start_time = clock();

  while (1) {
    // Get CPU usage
    char buffer[1024];
    int n = 0;
    FILE *fp = popen("top -bn1 | grep \"Cpu(s)\" | sed \"s/.*, *\\([0-9.]*\\)%* id.*/\\1/\" | awk '{print 100 - $1}'", "r");
    if (fp != NULL) {
      n = fread(buffer, 1, sizeof(buffer), fp);
      pclose(fp);
    }
    sscanf(buffer, "%f", &cpu);

    // Check if CPU usage is too high
    if (cpu > MAX_CPU_USAGE) {
      printf("High CPU usage detected! Shutting down...\n");
      system("shutdown -P now"); // Perform immediate system shutdown
    }

    // Print CPU usage info every second
    clock_t current_time = clock();
    if ((double) (current_time - start_time) / CLOCKS_PER_SEC >= sleep_time) {
      printf("CPU usage: %.2f%%\n", cpu);
      start_time = current_time;
    }

    // Check for sudden increase in CPU usage
    if (cpu - prev_cpu >= 20) {
      printf("Sudden increase in CPU usage detected! Taking action...\n");
      // Add code here to take action
    }

    prev_cpu = cpu;
  }

  return 0;
}