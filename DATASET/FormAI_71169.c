//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    // Declare variables
    char date[20];
    time_t t;
    struct tm tm;

    // Get user input
    printf("Enter a date in the format of dd/mm/yyyy: ");
    fgets(date, sizeof(date), stdin);

    // Convert string to time structure
    if (strptime(date, "%d/%m/%Y", &tm) == NULL)
    {
        printf("Invalid date format!\n");
        return 1;
    }
    t = mktime(&tm);

    // Get current date and time
    time_t current_time;
    struct tm *current_tm;
    current_time = time(NULL);
    current_tm = localtime(&current_time);

    // Calculate time difference
    double seconds = difftime(current_time, t);
    int days = (int) seconds / (60 * 60 * 24);

    // Print result
    printf("The date %s was %d days ago.\n", date, days);

    return 0;
}