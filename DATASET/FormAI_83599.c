//FormAI DATASET v1.0 Category: System boot optimizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Set the random number seed
  srand(time(NULL));

  // Define the system specs
  int num_processors = rand() % 8 + 1;
  int ram_size = (rand() % 7 + 1) * 2; // Ram sizes are power of 2
  int ssd_size = (rand() % 3 + 1) * 128;

  // Print out the specs
  printf("System specs:\n");
  printf("%d processors\n", num_processors);
  printf("%d GB RAM\n", ram_size);
  printf("%d GB SSD\n\n", ssd_size);

  // Calculate the boot time
  int boot_time = 0;
  boot_time += num_processors * 4;
  boot_time += ram_size / 2;
  boot_time += ssd_size / 64;

  // Print out the estimated boot time
  printf("Estimated boot time: %d seconds\n", boot_time);

  // Calculate the optimized boot time
  int optimized_boot_time = 0;
  optimized_boot_time += num_processors * 2;
  optimized_boot_time += ram_size / 4;
  optimized_boot_time += ssd_size / 32;

  // Print out the optimized estimated boot time
  printf("Optimized boot time: %d seconds\n", optimized_boot_time);

  return 0;
}