//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: brave
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main() {
  char buf[100];
  char usageStr[] = "cpu";
  char *usageVal;
  int fd, n, cpuUsage, prevCPUUsage;
  
  fd = open("/proc/stat", O_RDONLY);
  if (fd == -1) {
    printf("Error: failed to open /proc/stat\n");
    return -1;
  }

  while(1) {
    lseek(fd, 0, SEEK_SET);
    n = read(fd, buf, sizeof(buf));
    if (n <= 0) {
      printf("Error: failed to read /proc/stat\n"); 
      break;
    }
      
    buf[n] = '\0';
    usageVal = strstr(buf, usageStr);
    if (usageVal == NULL) {
      printf("Error: failed to parse cpu usage\n");
      break;
    }
    
    usageVal += strlen(usageStr) + 1;
    sscanf(usageVal, "%d", &cpuUsage);
    
    if (prevCPUUsage == 0) {
      prevCPUUsage = cpuUsage;
    } else {
      int usageDiff = cpuUsage - prevCPUUsage;
      prevCPUUsage = cpuUsage;
      printf("Current CPU usage: %d\n", usageDiff);
    }
    
    sleep(1);
  }
  
  close(fd);
  return 0;
}