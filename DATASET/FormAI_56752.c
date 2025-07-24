//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

  int memory_unit = 1024;
  int used_ram = 0;
  int max_ram = 8 * memory_unit;
  srand(time(0));

  printf("Welcome to the Surrealist C RAM Usage Monitor!\n");

  while(1) {

    used_ram = rand() % max_ram;  // generate a random number
    printf("Current RAM Usage: ");

    if (used_ram < 1024) {
      printf("%d bytes\n", used_ram);
    } else if (used_ram >= 1024 && used_ram < (1024 * memory_unit)) {
      printf("%d KB\n", used_ram / memory_unit);
    } else {
      printf("%d MB\n", used_ram / (memory_unit * memory_unit));
    }

    sleep(1); // wait one second before checking again
  }

  return 0;
}