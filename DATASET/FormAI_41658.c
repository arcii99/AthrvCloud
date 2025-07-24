//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main () {
    char date[11];
    printf("Please enter a date in natural language (e.g. January 1st, 2022): ");
    fgets(date, 11, stdin);
    date[strcspn(date, "\n")] = 0;  // Removes the newline character at the end
    
    char month[4], day[3], year[5];
    sscanf(date, "%s %s, %s", month, day, year);
    
    int month_num;
    if (strcmp(month, "January") == 0) {
        month_num = 1;
    } else if (strcmp(month, "February") == 0) {
        month_num = 2;
    } else if (strcmp(month, "March") == 0) {
        month_num = 3;
    } else if (strcmp(month, "April") == 0) {
        month_num = 4;
    } else if (strcmp(month, "May") == 0) {
        month_num = 5;
    } else if (strcmp(month, "June") == 0) {
        month_num = 6;
    } else if (strcmp(month, "July") == 0) {
        month_num = 7;
    } else if (strcmp(month, "August") == 0) {
        month_num = 8;
    } else if (strcmp(month, "September") == 0) {
        month_num = 9;
    } else if (strcmp(month, "October") == 0) {
        month_num = 10;
    } else if (strcmp(month, "November") == 0) {
        month_num = 11;
    } else if (strcmp(month, "December") == 0) {
        month_num = 12;
    } else {  // If the month isn't valid
        printf("Invalid month.\n");
        return;
    }
    
    printf("The corresponding numerical date is: %d/%s/%s\n", month_num, day, year);
}