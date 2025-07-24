//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

int monthToInt(char *month) {
    if (strcmp(month, "January") == 0) {
        return 1;
    } else if (strcmp(month, "February") == 0) {
        return 2;
    } else if (strcmp(month, "March") == 0) {
        return 3;
    } else if (strcmp(month, "April") == 0) {
        return 4;
    } else if (strcmp(month, "May") == 0) {
        return 5;
    } else if (strcmp(month, "June") == 0) {
        return 6;
    } else if (strcmp(month, "July") == 0) {
        return 7;
    } else if (strcmp(month, "August") == 0) {
        return 8;
    } else if (strcmp(month, "September") == 0) {
        return 9;
    } else if (strcmp(month, "October") == 0) {
        return 10;
    } else if (strcmp(month, "November") == 0) {
        return 11;
    } else if (strcmp(month, "December") == 0) {
        return 12;
    }
    return 0;
}

int main() {
    printf("Enter a date in the format 'Month Day, Year': ");
    char date_str[20];
    fgets(date_str, 20, stdin);

    char *month = strtok(date_str, " ");
    char *day_str = strtok(NULL, ", ");
    char *year_str = strtok(NULL, ", ");

    int day = atoi(day_str);
    int year = atoi(year_str);
    int monthNum = monthToInt(month);

    printf("The date you entered is: %d/%d/%d\n", monthNum, day, year);

    return 0;
}