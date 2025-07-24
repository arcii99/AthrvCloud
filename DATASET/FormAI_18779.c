//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    int d, m, y;
    
    printf("Enter the date in natural language format (e.g. January 1st 2022): ");
    fgets(input, 100, stdin);
    
    char *month = strtok(input, " ");
    char *day = strtok(NULL, " ");
    char *year = strtok(NULL, " ");
    
    if (month == NULL || day == NULL || year == NULL) {
        printf("Invalid input!\n");
        return 0;
    }
    
    if (day[strlen(day) - 2] == 's' || day[strlen(day) - 2] == 'd' || day[strlen(day) - 2] == 't') {
        // remove the suffix
        day[strlen(day) - 2] = '\0';
    }
    
    d = atoi(day);
    y = atoi(year);
    
    if (strcmp(month, "January") == 0) {
        m = 1;
    } else if (strcmp(month, "February") == 0) {
        m = 2;
    } else if (strcmp(month, "March") == 0) {
        m = 3;
    } else if (strcmp(month, "April") == 0) {
        m = 4;
    } else if (strcmp(month, "May") == 0) {
        m = 5;
    } else if (strcmp(month, "June") == 0) {
        m = 6;
    } else if (strcmp(month, "July") == 0) {
        m = 7;
    } else if (strcmp(month, "August") == 0) {
        m = 8;
    } else if (strcmp(month, "September") == 0) {
        m = 9;
    } else if (strcmp(month, "October") == 0) {
        m = 10;
    } else if (strcmp(month, "November") == 0) {
        m = 11;
    } else if (strcmp(month, "December") == 0) {
        m = 12;
    } else {
        printf("Invalid input!\n");
        return 0;
    }
    
    printf("The date in numerical format is %d/%d/%d\n", m, d, y);
    
    return 0;
}