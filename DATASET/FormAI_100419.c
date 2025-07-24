//FormAI DATASET v1.0 Category: Date and time ; Style: innovative
#include <stdio.h>
#include <time.h>

int main() {
   time_t current_time;
   struct tm *local_time;

   time(&current_time);
   local_time = localtime(&current_time);

   printf("Current Date and Time: %s", asctime(local_time));

   return 0;
}