//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: modular
#include <stdio.h>
#include <string.h>

int monthToInt(char month[]) {
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
    } else {
        return -1;
    }
}

int main() {
    char input[100];
    printf("Enter a date (e.g. January 1, 2022): ");
    fgets(input, sizeof(input), stdin);

    char month[10];
    int day, year;
    sscanf(input, "%s %d, %d", month, &day, &year);

    int monthNum = monthToInt(month);
    if (monthNum == -1) {
        printf("Invalid input\n");
        return 0;
    }

    printf("%d-%02d-%02d\n", year, monthNum, day);

    return 0;
}