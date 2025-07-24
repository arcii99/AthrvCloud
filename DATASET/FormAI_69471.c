//FormAI DATASET v1.0 Category: System boot optimizer ; Style: authentic
#include <stdio.h>

int main(void) {
  int boot_time, launch_time, wait_time;
  
  printf("Enter your current boot time in seconds: ");
  scanf("%d", &boot_time);
  
  printf("Enter your desired launch time in seconds: ");
  scanf("%d", &launch_time);
  
  wait_time = launch_time - boot_time;
  
  if (wait_time <= 0) {
    printf("Your desired launch time has already passed. Exiting program.\n");
    return 0;
  }
  
  printf("Your computer will launch in %d seconds.\n", wait_time);
  
  for (int i = 1; i <= wait_time; i++) {
    printf("%d ", wait_time - i);
    sleep(1);
  }
  
  printf("\nWelcome to your optimized boot time!\n");
  
  // Place additional optimization code here
  
  return 0;
}