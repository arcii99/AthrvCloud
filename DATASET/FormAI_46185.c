//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
    char date[20];
    char month[10];
    char year[10];
    int day;
    
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Enter a date in natural language format (e.g. January 1st 2022): ");
    scanf("%s %d %s %s", month, &day, date, year);

    // convert month string to number
    int monthNum = 0;
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
    }
    
    // output converted date
    printf("The date you entered is: %d/%s/%s\n", monthNum, date, year);
    
    return 0;
}