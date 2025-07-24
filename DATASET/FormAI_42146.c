//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <stdbool.h>

int year = 0, month = 0, day = 0;

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    } else {
        return false;
    }
}

void julianToGregorian(int days) {
    int y = 4713, m = 1, d = 1;
    while (days >= 365) {
        if (isLeapYear(y)) {
            if (days >= 366) {
                days -= 366;
                y--;
            }
        } else {
            days -= 365;
            y--;
        }
    }
    while (days != 0) {
        switch (m) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if (days >= 31) {
                    days -= 31;
                    m++;
                } else {
                    d += days;
                    days = 0;
                }
                break;
            case 2:
                if (isLeapYear(y)) {
                    if (days >= 29) {
                        days -= 29;
                        m++;
                    } else {
                        d += days;
                        days = 0;
                    }
                } else {
                    if (days >= 28) {
                        days -= 28;
                        m++;
                    } else {
                        d += days;
                        days = 0;
                    }
                }
                break;
            case 4: case 6: case 9: case 11:
                if (days >= 30) {
                    days -= 30;
                    m++;
                } else {
                    d += days;
                    days = 0;
                }
                break;
        }
    }
    year = y;
    month = m;
    day = d;
}

int main() {
    int days = 2459455;
    julianToGregorian(days);
    printf("The date is %d-%d-%d", day, month, year);
    return 0;
}