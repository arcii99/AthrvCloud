//FormAI DATASET v1.0 Category: Date and time ; Style: inquisitive
#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Today is %d-%d-%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    printf("The time is %d:%d:%d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("Do you know what day of the week it is?\n");
    char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf("It's %s!\n", days[tm.tm_wday]);
    printf("This week's date and time is %d-%d-%d %d:%d:%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("You can also enter a date and time to check the day of the week! Enter in the format dd-mm-yyyy hh:mm:ss\n");
    char date_time[20];
    fgets(date_time, 20, stdin);
    int dd, mm, yyyy, hh, min, ss;
    sscanf(date_time, "%d-%d-%d %d:%d:%d", &dd, &mm, &yyyy, &hh, &min, &ss);
    struct tm temp = {0};
    temp.tm_mday = dd;
    temp.tm_mon = mm - 1;
    temp.tm_year = yyyy - 1900;
    temp.tm_hour = hh;
    temp.tm_min = min;
    temp.tm_sec = ss;
    mktime(&temp);
    printf("The day of the week for %d-%d-%d %d:%d:%d is %s\n", dd, mm, yyyy, hh, min, ss, days[temp.tm_wday]);

    return 0;
}