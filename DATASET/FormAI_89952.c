//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE* file = fopen("/proc/stat", "r");
   if (!file) {
      printf("Unable to read /proc/stat\n");
      return -1;
   }

   // Read the first line of /proc/stat
   char line[1024];
   fgets(line, sizeof(line), file);

   // Parse the CPU times
   unsigned long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
   sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

   // Calculate CPU usage
   unsigned long long total_cpu_time = user + nice + system + idle + iowait + irq + softirq + steal;
   unsigned long long idle_cpu_time = idle + iowait;
   float cpu_usage = (total_cpu_time - idle_cpu_time) * 100.0 / total_cpu_time;

   // Print CPU usage
   printf("CPU usage: %.2f%%\n", cpu_usage);

   fclose(file);
   return 0;
}