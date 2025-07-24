//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: peaceful
#include <stdio.h> // standard input/output library
#include <stdlib.h> // standard library
#include <unistd.h> // for sleep function

int main() {
  int time = 0;
  printf("Peaceful CPU usage monitor:\n");

  while(1) { // infinite loop
    system("clear"); // clear the screen
    printf("Time: %d seconds\n", time++);

    // calculate CPU usage
    FILE *fp;
    char buffer[4096];
    double user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice, total, idle_percentage;
    fp = fopen("/proc/stat", "r");
    fgets(buffer, 4096, fp);
    sscanf(buffer, "cpu %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
    total = user + nice + system + idle + iowait + irq + softirq + steal;
    idle_percentage = 100.0 * idle / total;
    printf("CPU Usage: %.2lf%%\n\n", 100 - idle_percentage);

    sleep(1); // wait for 1 second
  }
  
  return 0;
}