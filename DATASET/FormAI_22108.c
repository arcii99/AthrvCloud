//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *months[] = {
    "",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

char *convert_month(int month) {
    // Converts month number to month name
    return (char *)months[month];
}

void convert_date(char date[]) {
    // Converts date from dd/mm/yyyy format to "month name dd, yyyy"
    char *day, *month, *year;
    day = strtok(date, "/");
    month = convert_month(atoi(strtok(NULL, "/")));
    year = strtok(NULL, "/");
    printf("%s %s, %s\n", month, day, year);
}

int main() {
    char date[11];
    printf("Enter date in dd/mm/yyyy format: ");
    fgets(date, 11, stdin);
    convert_date(date);
    return 0;
}