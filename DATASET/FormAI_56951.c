//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: realistic
#include<stdio.h>
#include<string.h>

//Function to return the month number
int monthNumber(char month[]) {
    if(strcmp(month, "January") == 0) return 1;
    if(strcmp(month, "February") == 0) return 2;
    if(strcmp(month, "March") == 0)    return 3;
    if(strcmp(month, "April") == 0)    return 4;
    if(strcmp(month, "May") == 0)  return 5;
    if(strcmp(month, "June") == 0) return 6;
    if(strcmp(month, "July") == 0) return 7;
    if(strcmp(month, "August") == 0)   return 8;
    if(strcmp(month, "September") == 0)    return 9;
    if(strcmp(month, "October") == 0)  return 10;
    if(strcmp(month, "November") == 0) return 11;
    if(strcmp(month, "December") == 0) return 12;
}

//Function to check if the year is a leap year
int isLeap(int year) {
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

int main() {
    int day, year, month;
    char monthName[15];
    printf("Enter date in format (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &day, &month, &year);

    switch(month) {
        case 1: strcpy(monthName, "January"); break;
        case 2: strcpy(monthName, "February"); break;
        case 3: strcpy(monthName, "March"); break;
        case 4: strcpy(monthName, "April"); break;
        case 5: strcpy(monthName, "May"); break;
        case 6: strcpy(monthName, "June"); break;
        case 7: strcpy(monthName, "July"); break;
        case 8: strcpy(monthName, "August"); break;
        case 9: strcpy(monthName, "September"); break;
        case 10: strcpy(monthName, "October"); break;
        case 11: strcpy(monthName, "November"); break;
        case 12: strcpy(monthName, "December"); break;
    }

    printf("Converted date is: %d %s %d\n", day, monthName, year);
    return 0;
}