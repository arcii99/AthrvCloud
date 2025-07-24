//FormAI DATASET v1.0 Category: Date and time ; Style: curious
#include <stdio.h>
#include <time.h>

const char* get_month_name(int month) {
    switch (month) {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "Unknown";
    }
}

int main() {
    printf("Hello there! My name is Curious, and I'm here to show you a unique example program for getting the current date and time in C.\n");

    time_t now = time(NULL);
    struct tm* tm = localtime(&now);

    int year = tm->tm_year + 1900;
    int month = tm->tm_mon + 1;
    int day = tm->tm_mday;
    int hour = tm->tm_hour;
    int minute = tm->tm_min;
    int second = tm->tm_sec;

    printf("\nLet's start with the current date:\n");
    printf("%s %d, %d\n", get_month_name(month), day, year);

    printf("\nNow, let's move on to the current time:\n");
    if (hour > 12) {
        printf("%02d:%02d:%02d PM\n", hour - 12, minute, second);
    } else {
        printf("%02d:%02d:%02d AM\n", hour, minute, second);
    }

    printf("\nAnd there you have it! I hope you enjoyed this unique example program.\n");
    return 0;
}