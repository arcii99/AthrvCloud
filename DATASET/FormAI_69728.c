//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LENGTH 100

int main() {
  char command[MAX_LENGTH];
  int ram_usage;

  while (1) {
    // Get RAM usage
    sprintf(command, "free -m | awk 'NR==2{printf \"%%s\", $3}'");
    FILE *ram_proc = popen(command, "r");
    fgets(command, MAX_LENGTH, ram_proc);
    ram_usage = atoi(command);

    // Display RAM usage
    printf("Current RAM usage: %dMB\n", ram_usage);

    // Wait for 1 second
    sleep(1);
  }
  
  return 0;
}