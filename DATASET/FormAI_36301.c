//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 30

typedef struct {
    char month[MAX_LEN];
    int day;
    int year;
} Date;

void convertDate(char* str, Date* date) {
    char* token = strtok(str, "/");
    strcpy(date->month, token);

    token = strtok(NULL, "/");
    date->day = atoi(token);

    token = strtok(NULL, "/");
    date->year = atoi(token);
}

void printDate(Date* date) {
    printf("%s %d, %d\n", date->month, date->day, date->year);
}

int main() {
    char strDate[MAX_LEN];
    Date date;

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in the format 'month/day/year':\n");
    scanf("%s", strDate);

    convertDate(strDate, &date);
    printDate(&date);

    return 0;
}