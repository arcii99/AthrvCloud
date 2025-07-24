//FormAI DATASET v1.0 Category: Date and time ; Style: sophisticated
#include <stdio.h>
#include <time.h>

int main() {
   time_t current_time;
   struct tm * time_info;
   char time_string[25];

   time(&current_time);
   time_info = localtime(&current_time);

   strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);  
  
   printf("Current date and time: %s\n", time_string);

   return 0;
}