//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: creative
#include <stdio.h>
#include <string.h>

char* monthName(int month);

int main() {
    int month, day, year;
    char date[12];
    char *monthString;

    printf("Enter date in format MM/DD/YYYY: ");
    fgets(date, 12, stdin);

    // Extract month, day, year from input string
    sscanf(date, "%d/%d/%d", &month, &day, &year);

    // Convert month number to month name
    monthString = monthName(month);

    // Output converted date
    printf("%s %d, %d\n", monthString, day, year);

    return 0;
}

char* monthName(int month) {
    // Array of month names
    char *monthNames[] = {"January", "February", "March", "April",
                          "May", "June", "July", "August",
                          "September", "October", "November", "December"};

    // Return month name based on month number
    return monthNames[month-1];
}