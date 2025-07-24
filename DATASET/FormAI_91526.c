//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CPU_USAGE_PATH "/proc/stat"
#define BUFFER_SIZE 1024

int main() {
  char buffer[BUFFER_SIZE];
  int fd = open(CPU_USAGE_PATH, O_RDONLY);

  if (fd < 0) {
    printf("Error: could not open %s\n", CPU_USAGE_PATH);
    exit(EXIT_FAILURE);
  }

  while (1) {
    lseek(fd, 0, SEEK_SET);

    if (read(fd, buffer, BUFFER_SIZE) <= 0) {
      printf("Error: could not read %s\n", CPU_USAGE_PATH);
      exit(EXIT_FAILURE);
    }

    char* token = strtok(buffer, " ");
    int total = 0;

    while (token != NULL) {
      if (strncmp(token, "cpu", 3) != 0) {
        break;
      }

      token = strtok(NULL, " ");

      if (token == NULL) {
        printf("Error: could not parse %s\n", CPU_USAGE_PATH);
        exit(EXIT_FAILURE);
      }

      int usage = atoi(token);
      total += usage;
      token = strtok(NULL, " ");
    }

    printf("CPU Usage: %d%\n", total);
    sleep(1);
  }

  return 0;
}