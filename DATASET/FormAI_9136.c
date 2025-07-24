//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

#define MAX_DATE_LEN 15

// Function to convert natural language date to normal date format.
char* convertDate(char* natural_date) {
    char* date = (char*)malloc(MAX_DATE_LEN * sizeof(char));
    char day[3], month[10], year[5];
    int month_num = -1, year_num = -1;

    // Extract day, month and year from the natural language date.
    sscanf(natural_date, "%s %s %s", day, month, year);

    // Convert month and year to numbers.
    if (strcmp(month, "January") == 0) month_num = 1;
    else if (strcmp(month, "February") == 0) month_num = 2;
    else if (strcmp(month, "March") == 0) month_num = 3;
    else if (strcmp(month, "April") == 0) month_num = 4;
    else if (strcmp(month, "May") == 0) month_num = 5;
    else if (strcmp(month, "June") == 0) month_num = 6;
    else if (strcmp(month, "July") == 0) month_num = 7;
    else if (strcmp(month, "August") == 0) month_num = 8;
    else if (strcmp(month, "September") == 0) month_num = 9;
    else if (strcmp(month, "October") == 0) month_num = 10;
    else if (strcmp(month, "November") == 0) month_num = 11;
    else if (strcmp(month, "December") == 0) month_num = 12;

    if (strcmp(year, "twenty-sixty-nine") == 0) year_num = 2069;
    else if (strcmp(year, "twenty-seventy") == 0) year_num = 2070;
    else if (strcmp(year, "twenty-seventy-one") == 0) year_num = 2071;
    else if (strcmp(year, "twenty-seventy-two") == 0) year_num = 2072;

    // Build the normal date format string.
    sprintf(date, "%02d/%02d/%d", atoi(day), month_num, year_num);

    return date;
}

int main() {
    char natural_date[MAX_DATE_LEN];
    printf("Enter a natural language date: ");
    fgets(natural_date, MAX_DATE_LEN, stdin);
    char* date = convertDate(natural_date);
    printf("Normal date: %s\n", date);
    free(date);
    return 0;
}