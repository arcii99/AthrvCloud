//FormAI DATASET v1.0 Category: Date and time ; Style: sophisticated
#include <stdio.h>
#include <time.h>

int main() {
   time_t current_time = time(NULL); // Get current time in seconds since epoch
   struct tm* current_time_tm = localtime(&current_time); // Convert seconds to a struct tm
   
   printf("Current date and time: %s", asctime(current_time_tm)); // Print current date and time
   
   // Example of setting a custom date and time
   struct tm custom_time_tm = {0}; // Initialize struct with all fields set to 0
   custom_time_tm.tm_year = 121; // Year since 1900, 2021-1900 = 121
   custom_time_tm.tm_mon = 0; // Month, January = 0
   custom_time_tm.tm_mday = 1; // Day of month
   custom_time_tm.tm_hour = 12; // Hour
   custom_time_tm.tm_min = 0; // Minute
   custom_time_tm.tm_sec = 0; // Second
   
   time_t custom_time = mktime(&custom_time_tm); // Convert custom time to seconds since epoch
   struct tm* custom_time_tm_ptr = localtime(&custom_time); // Convert seconds to a struct tm
   
   printf("Custom date and time: %s", asctime(custom_time_tm_ptr)); // Print custom date and time
   
   return 0;
}