//FormAI DATASET v1.0 Category: System boot optimizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));
  int num_apps = rand() % 50 + 1;
  int num_services = rand() % 20 + 1;
  int num_startup = rand() % 10 + 1;
  int boot_time = rand() % 100 + 1;

  printf("Welcome to the C System boot optimizer! We're going to randomly generate some data to optimize your boot time!\n\n");
  printf("We've randomly determined that you have %d startup applications, %d running services, and %d startup processes that we can potentially optimize. Your current boot time is %d seconds.\n\n", num_apps, num_services, num_startup, boot_time);

  int num_hung_apps = rand() % num_apps;
  int num_hung_services = rand() % num_services;
  int num_hung_startup = rand() % num_startup;

  printf("Oh no! We've found that %d applications, %d services, and %d startup processes are causing your slower boot time. But don't worry! We'll optimize those for you.\n\n", num_hung_apps, num_hung_services, num_hung_startup);

  int optimized_apps = num_apps - num_hung_apps;
  int optimized_services = num_services - num_hung_services;
  int optimized_startup = num_startup - num_hung_startup;

  int optimized_boot_time = boot_time - (num_hung_apps * 2) - (num_hung_services * 5) - (num_hung_startup * 3);

  printf("After optimizing your system, we were able to eliminate %d apps, %d services, and %d startup processes. We were also able to reduce your boot time by %d seconds! You're welcome!\n\n", num_hung_apps, num_hung_services, num_hung_startup, boot_time - optimized_boot_time);

  printf("Thank you for using the C System boot optimizer! Your system is now fully optimized!\n\n");

  return 0;
}