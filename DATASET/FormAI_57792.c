//FormAI DATASET v1.0 Category: Date and time ; Style: calm
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    time_t datetime;
    struct tm * datetime_info; 
    char datetime_str[30];
    
    // Get current date and time
    datetime = time(NULL);
    datetime_info = localtime(&datetime);

    // Format date and time
    strftime(datetime_str, 30, "%Y/%m/%d %H:%M:%S", datetime_info);

    // Output formatted date and time
    printf("The current date and time is: %s\n", datetime_str);

    // Prompt for a new date
    printf("Enter a date in the format YYYY/MM/DD: ");
    scanf("%s", datetime_str);

    // Convert string to struct tm
    strptime(datetime_str,"%Y/%m/%d",datetime_info);
    // Set time to midnight
    datetime_info->tm_hour = 0;
    datetime_info->tm_min = 0;
    datetime_info->tm_sec = 0;

    // Convert struct tm to time_t
    datetime = mktime(datetime_info);

    // Output the selected date
    printf("You entered: ");
    strftime(datetime_str, 30, "%Y/%m/%d", datetime_info);
    printf("%s\n", datetime_str);

    // Output the number of seconds since the epoch
    printf("That is %ld seconds since the epoch\n", datetime);

    return 0;
}