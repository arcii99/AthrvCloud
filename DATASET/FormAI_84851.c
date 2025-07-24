//FormAI DATASET v1.0 Category: Date and time ; Style: introspective
#include <stdio.h>
#include <time.h>

int main() {
    // Get current time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Print current date and time
    printf("Current date and time: %02d/%02d/%04d %02d:%02d:%02d\n", 
        tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

    // Prompt user to enter a date and time
    printf("Please enter a date and time in the dd/mm/yyyy hh:mm:ss format: ");
    char input[20];
    fgets(input, 20, stdin);
    
    // Parse user input
    int day, month, year, hour, minute, second;
    sscanf(input, "%d/%d/%d %d:%d:%d", &day, &month, &year, &hour, &minute, &second);

    // Convert user input to time_t format
    struct tm user_tm = {0};
    user_tm.tm_year = year - 1900;
    user_tm.tm_mon = month - 1;
    user_tm.tm_mday = day;
    user_tm.tm_hour = hour;
    user_tm.tm_min = minute;
    user_tm.tm_sec = second;
    time_t user_t = mktime(&user_tm);

    // Compare user input to current time
    double diff_seconds = difftime(user_t, t);
    int diff_days = diff_seconds / (60 * 60 * 24);

    // Print results
    if (diff_days == 0) {
        printf("The entered date and time is the same as the current date and time.\n");
    } else if (diff_days < 0) {
        printf("The entered date and time is %d days and %d seconds in the past.\n", 
            abs(diff_days), (int)fmod(diff_seconds, 60 * 60 * 24));
    } else {
        printf("The entered date and time is %d days and %d seconds in the future.\n", 
            diff_days, (int)fmod(diff_seconds, 60 * 60 * 24));
    }

    return 0;
}