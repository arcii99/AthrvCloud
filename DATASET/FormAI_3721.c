//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // Initialize variables
    int day, year;
    char month[10];
    
    // Input date from user in natural language
    printf("Enter date in natural language (E.g. January 1, 2022): ");
    scanf("%s %d, %d", month, &day, &year);
    
    // Convert month to number
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
    } else {
        printf("Invalid month\n");
        return 1;
    }
    
    // Print date in ISO format
    printf("ISO format: %d-%02d-%02d\n", year, month_num, day);
    
    return 0;
}