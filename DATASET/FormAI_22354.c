//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: secure
#include<stdio.h>
#include<string.h>

// Function to return the number of days in a month
int daysInMonth(int month, int year){
    int days;

    // February
    if (month == 2){
        // Leap year
        if (year % 4 == 0){
            if (year % 100 == 0){
                if (year % 400 == 0){
                    days = 29;
                } else {
                    days = 28;
                }
            } else {
                days = 29;
            }
        } else {
            days = 28;
        }

    // April, June, September, November
    } else if (month == 4 || month == 6 || 
               month == 9 || month == 11){
        days = 30;
    } else {
        days = 31;
    }

    return days;
}

int main(){
    char date[11];
    int day, month, year, daysCount = 0, i;

    printf("Enter date in format dd/mm/yyyy: ");
    scanf("%s", date);

    // Extracting day, month and year from the date string
    day = (date[0] - '0') * 10 + (date[1] - '0');
    month = (date[3] - '0') * 10 + (date[4] - '0');
    year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + 
           (date[8] - '0') * 10 + (date[9] - '0');

    // Validating the date
    if (year < 1 || year > 9999 || month < 1 || month > 12 || 
        day < 1 || day > daysInMonth(month, year)){
        printf("Invalid date.");
        return 0;
    }

    // Counting the number of days from year 1
    for (i = 1; i < year; i++){
        if (i % 4 == 0){
            if (i % 100 == 0){
                if (i % 400 == 0){
                    daysCount += 366;
                } else {
                    daysCount += 365;
                }
            } else {
                daysCount += 366;
            }
        } else {
            daysCount += 365;
        }
    }

    // Counting the number of days from year start to input date
    for (i = 1; i < month; i++){
        daysCount += daysInMonth(i, year);
    }

    daysCount += day - 1;

    printf("The number of days from year 1 to %s is %d.\n", date, daysCount);

    return 0;
}