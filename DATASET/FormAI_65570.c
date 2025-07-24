//FormAI DATASET v1.0 Category: System boot optimizer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void clear_buffer() {
   char c;
   while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
   int boot_time, program_startup, user_input;
   printf("Welcome to C System Boot Optimizer!\n");
   printf("Please enter the time it takes for your system to boot (in seconds): ");
   scanf("%d", &boot_time);
   clear_buffer();

   printf("Please enter the time it takes for your system's programs to start up (in seconds): ");
   scanf("%d", &program_startup);
   clear_buffer();

   printf("Your current system start-up time is %d seconds.\n", boot_time + program_startup);
   printf("How much faster would you like your system to boot?\n");
   printf("Enter the percentage increase in speed (e.g. enter 10 for 10%% faster): ");
   scanf("%d", &user_input);
   clear_buffer();

   printf("Analyzing boot sequence...\n");
   int speed_increase = (boot_time + program_startup) * user_input / 100;
   int total_time = (boot_time + program_startup) - speed_increase;
   printf("Speed increase: %d seconds less\n", speed_increase);
   printf("New system start-up time: %d seconds\n", total_time);
   printf("Applying optimizations...\n");
   printf("Done! Your system will now boot %d seconds faster.\n", speed_increase);

   return 0;
}