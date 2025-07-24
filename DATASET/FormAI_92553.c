//FormAI DATASET v1.0 Category: System boot optimizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {  
  printf("Welcome to the C System Boot Optimizer!\n");
  srand(time(0));
  
  int boot_time = rand() % 20 + 10;
  printf("Your system will boot up in %d seconds.\n", boot_time);
  printf("Starting boot sequence...\n\n");
  
  for (int i = 1; i <= boot_time; i++) {
    if (i < boot_time/2) {
      printf("Loading module %d... %d%%\n", i, i*5);
    } else if (i == boot_time/2) {
      printf("    *** Optimizing boot sequence ***\n\n");
    } else {
      printf("Loading module %d... %d%%\n", i, (boot_time - i)*5);
    }
    sleep(1);
  }
  
  printf("\nSystem boot complete in %d seconds.\n", boot_time);
  printf("Optimization successful. Enjoy your speedy system!\n");
  
  return 0;
}