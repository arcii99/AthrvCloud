//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  while(1) {
    FILE *fptr;
    char buffer[1024];
    char *command = "ps -p %d -o %%cpu | awk '{print $1}'";
    pid_t pid = getpid();
    sprintf(buffer, command, pid);
    fptr = popen(buffer, "r");

    if(fptr == NULL) {
      printf("Unable to open command.\n");
      exit(0);
    }

    float cpu_usage;
    fscanf(fptr, "%f", &cpu_usage);
    printf("Current CPU Usage: %.2f %%\n", cpu_usage);

    pclose(fptr);

    usleep(500000); // Sleep for 500 milliseconds
  }

  return 0;
}