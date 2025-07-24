//FormAI DATASET v1.0 Category: System boot optimizer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("C System Boot Optimizer\n\n");

  // Generate random boot times
  srand(time(NULL));
  int boot_times[10];
  printf("Generating random boot times...\n");
  for (int i = 0; i < 10; i++) {
    boot_times[i] = rand() % 61;
    printf("Boot time %d: %d seconds\n", i+1, boot_times[i]);
  }

  // Find the shortest boot time
  int shortest_boot_time = boot_times[0];
  for (int i = 1; i < 10; i++) {
    if (boot_times[i] < shortest_boot_time) {
      shortest_boot_time = boot_times[i];
    }
  }
  printf("\nShortest boot time: %d seconds\n", shortest_boot_time);

  // Optimize boot order based on shortest boot time
  printf("\nOptimizing boot order...\n");
  for (int i = 0; i < 10; i++) {
    int index_of_shortest_boot_time = -1;
    for (int j = i; j < 10; j++) {
      if (boot_times[j] == shortest_boot_time) { 
        index_of_shortest_boot_time = j;
        break;
      }
    }
    if (index_of_shortest_boot_time != -1) {
      printf("Booting system %d with boot time %d seconds\n", index_of_shortest_boot_time+1, boot_times[index_of_shortest_boot_time]);
      int temp = boot_times[i];
      boot_times[i] = boot_times[index_of_shortest_boot_time];
      boot_times[index_of_shortest_boot_time] = temp;
    }
    else {
      printf("Booting system %d with boot time %d seconds\n", i+1, boot_times[i]);
    }
  }

  printf("\nOptimization complete!\n");

  return 0;
}