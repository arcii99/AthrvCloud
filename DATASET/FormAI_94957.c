//FormAI DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Happy System Administration program!\n");

  // Declare the system variables
  int cpuUsage = 25;
  int memoryUsage = 50;
  int diskUsage = 75;

  printf("Current system statistics:\n");
  printf("CPU usage: %d%%\n", cpuUsage);
  printf("Memory usage: %d%%\n", memoryUsage);
  printf("Disk usage: %d%%\n", diskUsage);

  // Check for any issues
  if (cpuUsage > 80) {
    printf("Uh-oh, CPU usage is higher than expected!\n");
    printf("We'll need to investigate this further...\n");
  } else {
    printf("Great news, CPU usage is within normal range!\n");
  }

  if (memoryUsage > 90) {
    printf("Yikes, looks like we're running low on memory!\n");
    printf("Let's check what's using up all the memory...\n");
  } else {
    printf("Phew, memory usage is perfectly fine!\n");
  }

  if (diskUsage > 95) {
    printf("Houston, we have a problem - disk space is critically low!\n");
    printf("We'll need to free up some space ASAP...\n");
  } else {
    printf("Excellent, there's plenty of disk space remaining!\n");
  } 

  printf("Thank you for using the Happy System Administration program!\n");
  return 0;
}