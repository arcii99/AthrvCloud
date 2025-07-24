//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_FILE_SIZE 255

void get_cpu_usage(char *cpu_usage) {
  char file_path[MAX_FILE_SIZE];
  int fd;
  char buff[MAX_FILE_SIZE];

  snprintf(file_path, MAX_FILE_SIZE, "/proc/stat");

  fd = open(file_path, O_RDONLY);

  if(fd == -1) {
    printf("Error opening /proc/stat\n");
    exit(EXIT_FAILURE);
  }

  if(read(fd, buff, MAX_FILE_SIZE) < 0) {
    printf("Error reading from file\n");
    exit(EXIT_FAILURE);
  }

  // Get the CPU usage from the buff
  sscanf(buff, "cpu %s", cpu_usage);

  close(fd);

}

int main() {
  char cpu_usage_previous[MAX_FILE_SIZE], cpu_usage_current[MAX_FILE_SIZE], cpu_diff[MAX_FILE_SIZE]="";
  float cpu_percentage;

  get_cpu_usage(cpu_usage_previous);

  while(1) {
    get_cpu_usage(cpu_usage_current);

    int i;
    for(i=0; i < strlen(cpu_usage_current); i++) {
      if(!isdigit(cpu_usage_current[i])) {
        cpu_usage_current[i] = '\0';
        break;
      }
    }

    int cpu_diff_int = atoi(cpu_usage_current) - atoi(cpu_usage_previous);

    snprintf(cpu_diff, MAX_FILE_SIZE, "%d", cpu_diff_int);

    cpu_percentage = (float)cpu_diff_int / 100;
    printf("CPU usage: %.2f%%\n", cpu_percentage);

    strcpy(cpu_usage_previous, cpu_usage_current);

    sleep(1);
  }

  return 0;
}