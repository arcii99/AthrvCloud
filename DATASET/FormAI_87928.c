//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: high level of detail
#include <stdio.h>
#include <string.h>

void convertDate(char date[]);

int main() {
    char date[11];
    printf("Enter a date in natural language (ex: January 1, 2022): ");
    fgets(date, sizeof(date), stdin); // gets user input
    convertDate(date);
    return 0;
}

void convertDate(char date[]) {
    char month[10], day[3], year[5];
    int monthNum;
    sscanf(date, "%s %s, %s", month, day, year); // separate month, day, and year from input
    
    if (strcmp(month, "January") == 0) {
        monthNum = 1;
    } else if (strcmp(month, "February") == 0) {
        monthNum = 2;
    } else if (strcmp(month, "March") == 0) {
        monthNum = 3;
    } else if (strcmp(month, "April") == 0) {
        monthNum = 4;
    } else if (strcmp(month, "May") == 0) {
        monthNum = 5;
    } else if (strcmp(month, "June") == 0) {
        monthNum = 6;
    } else if (strcmp(month, "July") == 0) {
        monthNum = 7;
    } else if (strcmp(month, "August") == 0) {
        monthNum = 8;
    } else if (strcmp(month, "September") == 0) {
        monthNum = 9;
    } else if (strcmp(month, "October") == 0) {
        monthNum = 10;
    } else if (strcmp(month, "November") == 0) {
        monthNum = 11;
    } else if (strcmp(month, "December") == 0) {
        monthNum = 12;
    } else {
        printf("Invalid month entered.\n");
        return;
    }
    
    printf("%d/%s/%s\n", monthNum, day, year); // output converted date
}