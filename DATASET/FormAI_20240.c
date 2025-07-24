//FormAI DATASET v1.0 Category: Date and time ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   time_t current_time;
   struct tm * time_info;
   char time_string[40];

   time(&current_time);
   time_info = localtime(&current_time);

   strftime(time_string, sizeof(time_string), "%m/%d/%Y %H:%M:%S", time_info);

   printf("Current time: %s\n", time_string);

   return 0;
}