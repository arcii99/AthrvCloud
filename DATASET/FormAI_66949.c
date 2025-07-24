//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: introspective
#include <stdio.h>
#include <time.h>

int main() {
    // get current time
    time_t now = time(NULL);

    // prompt user to enter a year to travel to
    printf("Think of a year and enter it: ");
    int future_year;
    scanf("%d", &future_year);

    // calculate number of years from current time to future year
    int years_to_travel = future_year - 1900 - localtime(&now)->tm_year;

    // calculate the timestamp for the future year
    time_t future_time = now + (years_to_travel * 365 * 24 * 60 * 60);

    // convert the future timestamp to a tm struct
    struct tm *future_tm = localtime(&future_time);

    // print out the result
    printf("In the year %d, it will be %s\n", future_year, asctime(future_tm));

    return 0;
}