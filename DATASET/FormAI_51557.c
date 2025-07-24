//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

struct date {
    int day;
    int month;
    int year;
};

int isLeapYear(int year) {
    if((year % 4 == 0 && year % 100 !=0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int daysInMonth(int month, int year) {
    switch(month) {
        case 1:
            return 31;
            break;
        case 2:
            if(isLeapYear(year)) {
                return 29;
            } else {
                return 28;
            }
            break;
        case 3:
            return 31;
            break;
        case 4:
            return 30;
            break;
        case 5:
            return 31;
            break;
        case 6:
            return 30;
            break;
        case 7:
            return 31;
            break;
        case 8:
            return 31;
            break;
        case 9:
            return 30;
            break;
        case 10:
            return 31;
            break;
        case 11:
            return 30;
            break;
        case 12:
            return 31;
            break;
        default:
            printf("Invalid date!\n");
            break;
    }
}

void addDays(int *day, int *month, int *year, int daysToAdd) {
    while(daysToAdd != 0) {
        int daysInCurrentMonth = daysInMonth(*month, *year);
        if(*day + daysToAdd <= daysInCurrentMonth) {
            *day += daysToAdd;
            daysToAdd = 0;
        } else {
            daysToAdd -= (daysInCurrentMonth - *day) + 1;
            *day = 1;
            if(*month == 12) {
                *year += 1;
                *month = 1;
            } else {
                *month += 1;
            }
        }
    }
}

int main() {
    struct date myDate;
    printf("Enter a date in the format of dd mm yyyy: ");
    scanf("%d %d %d", &myDate.day, &myDate.month, &myDate.year);

    int daysToAdd;
    printf("Enter the number of days to add: ");
    scanf("%d", &daysToAdd);

    addDays(&myDate.day, &myDate.month, &myDate.year, daysToAdd);

    printf("The new date is: %d %d %d\n", myDate.day, myDate.month, myDate.year);

    return 0;
}