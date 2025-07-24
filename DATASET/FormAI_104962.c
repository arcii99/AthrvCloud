//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: relaxed
#include <stdio.h>

//Function to determine if the year is a leap year or not
int isLeapYear(int year){
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        return 1;
    } else {
        return 0;
    }
}

//Function to determine the number of days in a given month of a given year
int numDaysInMonth(int month, int year){
    int numDays;
    switch(month){
        case 1: 
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            numDays = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            numDays = 30;
            break;
        case 2:
            if(isLeapYear(year)){
                numDays = 29;
            } else {
                numDays = 28;
            }
            break;
        default:
            printf("Invalid month\n");
            break;
    }
    return numDays;
}

int main(){
    int day, month, year;

    printf("Please enter the date in natural language format (e.g. January 1, 2022):\n");
    scanf("%d %*c %d %*c %d", &month, &day, &year);

    //Validation checks
    if(month > 12 || month < 1){
        printf("Invalid month\n");
        return 0;
    }
    if(day > numDaysInMonth(month, year) || day < 1){
        printf("Invalid day\n");
        return 0;
    }

    //Output in desired format
    printf("\nYour date in C format is: %d-%02d-%02d\n", year, month, day);

    return 0;
}