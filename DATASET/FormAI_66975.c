//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: retro
#include<stdio.h>
#include<string.h>

int main(){
    char date[20];
    printf("Enter a date in natural language (e.g. January 1, 2000): ");
    fgets(date, 20, stdin);

    int month, day, year;
    char month_str[10];

    sscanf(date, "%s %d, %d", month_str, &day, &year);

    if(strcmp(month_str, "January") == 0)
        month = 1;
    else if(strcmp(month_str, "February") == 0)
        month = 2;
    else if(strcmp(month_str, "March") == 0)
        month = 3;
    else if(strcmp(month_str, "April") == 0)
        month = 4;
    else if(strcmp(month_str, "May") == 0)
        month = 5;
    else if(strcmp(month_str, "June") == 0)
        month = 6;
    else if(strcmp(month_str, "July") == 0)
        month = 7;
    else if(strcmp(month_str, "August") == 0)
        month = 8;
    else if(strcmp(month_str, "September") == 0)
        month = 9;
    else if(strcmp(month_str, "October") == 0)
        month = 10;
    else if(strcmp(month_str, "November") == 0)
        month = 11;
    else if(strcmp(month_str, "December") == 0)
        month = 12;
    else{
        printf("Invalid date format!\n");
        return 0;
    }

    printf("Date in numerical format is: %d/%d/%d\n", month, day, year);

    return 0;
}