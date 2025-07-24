//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLeap(int year){
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

void convertDate(char date[]){
    int day, year, month;
    char monthList[] = {"January February March April May June July August September October November December"};
    char delimiter[] = " ";
    char *token;
    token = strtok(date, delimiter);
    month = atoi(token);
    token = strtok(NULL, delimiter);
    day = atoi(token);
    token = strtok(NULL, delimiter);
    year = atoi(token);

    int monDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysCount = 0;

    for(int i = 0; i < month - 1; i++)
        daysCount += monDays[i];

    daysCount += day;

    if(isLeap(year) && month > 2)
        daysCount += 1;

    printf("The date %s is the %dth day of the year %d\n", date, daysCount, year);
}

int main(){
    char date[20];
    printf("Enter a date (mm dd yyyy): ");
    fgets(date,20,stdin);
    convertDate(date);
    return 0;
}