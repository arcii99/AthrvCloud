//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep()

int main() {
  int previous_cpu_usage = 0;
  
  while (1) { // infinite loop
    FILE* fp = fopen("/proc/stat", "r");
    if (! fp) {
      fprintf(stderr, "Error: Unable to open /proc/stat\n");
      exit(1);
    }
    
    char buffer[1024];
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);
    
    int cpu_usage = 0;
    int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    
    sscanf(buffer, "cpu %d %d %d %d %d %d %d %d %d %d",
            &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
    int total_jiffies = user + nice + system + idle + iowait + irq + softirq + steal;
    int diff_jiffies = total_jiffies - previous_cpu_usage;
    cpu_usage = (diff_jiffies * 100) / (1 + diff_jiffies + idle - previous_cpu_usage);
    previous_cpu_usage = total_jiffies - idle;
    
    // clear the screen
    printf("\e[1;1H\e[2J"); // this is an ANSI escape sequence
    
    printf("CPU usage: %d%%\n\n", cpu_usage);
    printf("  User:    %d%%\n", (user * 100) / total_jiffies);
    printf("  Nice:    %d%%\n", (nice * 100) / total_jiffies);
    printf("  System:  %d%%\n", (system * 100) / total_jiffies);
    printf("  Idle:    %d%%\n", (idle * 100) / total_jiffies);
    printf("  IOWait:  %d%%\n", (iowait * 100) / total_jiffies);
    printf("  IRQ:     %d%%\n", (irq * 100) / total_jiffies);
    printf("  SoftIRQ: %d%%\n", (softirq * 100) / total_jiffies);
    printf("  Steal:   %d%%\n", (steal * 100) / total_jiffies);
    printf("  Guest:   %d%%\n", (guest * 100) / total_jiffies);
    printf("  Guest_nice: %d%%\n", (guest_nice * 100) / total_jiffies);
    
    sleep(1); // wait for 1 second
  }
  
  return 0;
}