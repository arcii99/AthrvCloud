//FormAI DATASET v1.0 Category: Date and time ; Style: imaginative
#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Current date and time:\n");
    printf("%d-%02d-%02d %02d:%02d:%02d\n",
           tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
           tm.tm_hour, tm.tm_min, tm.tm_sec);

    // Let's add some creativity to the program
    int days_remaining_yr = 365 - tm.tm_yday; // Days remaining in current year
    int days_till_christmas = 25 - (tm.tm_mday - tm.tm_yday); // Days till Christmas
    int seconds_since_epoch = (int)time(NULL); // Time elapsed since the Epoch

    printf("\nSome more unique info:\n");
    printf("Remaining days in the year: %d\n", days_remaining_yr);
    printf("Days till Christmas: %d\n", days_till_christmas);
    printf("Seconds since the Epoch: %d\n", seconds_since_epoch);

    return 0;
}