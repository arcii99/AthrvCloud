//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int ram;
  char command[50];
  while (1) {
    // Execute command to get RAM usage
    sprintf(command, "free | grep Mem | awk '{print $3/$2 * 100.0}'");
    FILE* output = popen(command, "r");
    fscanf(output, "%d", &ram);
    pclose(output);

    // Check if RAM usage exceeds limit
    if (ram > 80) {
      printf("Warning: High RAM usage detected! Current usage: %d%%.\n", ram);
      printf("Attempting to free up RAM...\n");

      // Execute command to free up cached memory
      system("sync; echo 3 > /proc/sys/vm/drop_caches");

      // Check if freeing up memory was successful
      output = popen(command, "r");
      fscanf(output, "%d", &ram);
      pclose(output);

      if (ram <= 50) {
        printf("RAM usage was successfully reduced to %d%%.\n", ram);
      } else {
        printf("Unable to reduce RAM usage. Current usage: %d%%.\n", ram);
      }
    } else {
      printf("RAM usage is currently at %d%%.\n", ram);
    }

    sleep(10); // Wait for 10 seconds before checking RAM usage again
  }

  return 0;
}