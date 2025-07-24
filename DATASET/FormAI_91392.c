//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing variables
    int day, month, year, hour, minute;
    char name[50], apt_type[50];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    // Collecting user inputs
    printf("Welcome to the Post-Apocalyptic Appointment Scheduler\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Appointment type (e.g. medical, dental, repair, etc.): ");
    scanf("%s", apt_type);
    printf("Date of appointment (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);
    printf("Time of appointment (hh:mm): ");
    scanf("%d:%d", &hour, &minute);

    // Calculating time difference between current time and appointment time
    time_t apt_time = mktime(&t);
    struct tm apt_tm = *localtime(&apt_time);
    apt_tm.tm_hour = hour;
    apt_tm.tm_min = minute;
    apt_tm.tm_sec = 0;
    apt_tm.tm_mday = day;
    apt_tm.tm_mon = month-1;
    apt_tm.tm_year = year-1900;
    time_t apt_unix = mktime(&apt_tm);
    double diff_sec = difftime(apt_unix, now);

    // Printing out appointment details and time difference
    printf("\n\nYour %s appointment with %s is scheduled for:\n", apt_type, name);
    printf("%d/%d/%d at %02d:%02d\n", day, month, year, hour, minute);
    printf("That's in %2.f seconds or %2.f minutes or %2.f hours.\n", diff_sec, diff_sec/60, diff_sec/3600);

    return 0;
}