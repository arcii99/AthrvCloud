//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include <stdio.h>
#include <unistd.h>

int main(void) {
   const float MIN_THRESHOLD = 10.0; // minimum threshold percent
   const int SLEEP_TIME = 1; // sleep interval in seconds
   int counter = 0; // counter to keep track of the number of iterations
   float total_cpu = 0.0; // total cpu usage

   while (1) { // infinite loop to monitor cpu usage
      char buf[256];
      FILE *fp = fopen("/proc/stat", "r");

      if (!fp) {
         printf("Error: could not open /proc/stat\n");
         return 1;
      }

      fgets(buf, 256, fp);
      fclose(fp);

      unsigned long long int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
      sscanf(buf, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

      unsigned long long int total_cpu_time = user + nice + system + idle + iowait + irq + softirq + steal;
      float cpu_usage = 100.0 - (((float)idle / (float)total_cpu_time) * 100.0);

      total_cpu += cpu_usage;
      counter++;

      printf("CPU usage: %.2f%%\n", cpu_usage);

      if (cpu_usage >= MIN_THRESHOLD) {
         printf("WARNING: High CPU usage detected!\n");
      }

      sleep(SLEEP_TIME);
   }

   float avg_cpu_usage = total_cpu / counter;

   printf("Average CPU usage: %.2f%%\n", avg_cpu_usage);

   return 0;
}