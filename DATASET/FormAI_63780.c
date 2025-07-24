//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char date[50];
    int day, month, year, hours, minutes, seconds = 0;

    printf("Enter a date in natural language format (e.g. January 1st 2022 at 2:30pm): ");
    fgets(date, sizeof(date), stdin);

    if (sscanf(date, "%d %*s %d %d at %d:%d%*s", &month, &day, &year, &hours, &minutes) == 5) {
        // Time specified
        if ((strstr(date, "pm") || strstr(date, "PM")) && hours != 12) {
            // Convert to military time
            hours += 12;
        } else if ((strstr(date, "am") || strstr(date, "AM")) && hours == 12) {
            // Midnight
            hours = 0;
        }

        printf("The date in ISO format is: %d-%02d-%02dT%02d:%02d:%02d+00:00\n", year, month, day, hours, minutes, seconds);
    } else if (sscanf(date, "%d %*s %d %d", &month, &day, &year) == 3) {
        // Date only
        printf("The date in ISO format is: %d-%02d-%02dT%02d:%02d:%02d+00:00\n", year, month, day, hours, minutes, seconds);
    } else {
        printf("I'm sorry, I couldn't understand the date you entered. Please try again.\n");
    }

    return 0;
}