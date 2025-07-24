//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <time.h>

enum Format { DAY_MONTH_YEAR, MONTH_DAY_YEAR };

time_t convertToTime(char* dateString, enum Format format) {
    char* formatString = format == DAY_MONTH_YEAR ? "%d-%m-%Y" : "%m-%d-%Y";
    struct tm tm = {0};

    strptime(dateString, formatString, &tm);
    time_t time = mktime(&tm);

    return time;
}

int main() {
    char* dateString = "12-05-2022";  // Replace with your date
    enum Format format = DAY_MONTH_YEAR;  // Change to MONTH_DAY_YEAR if necessary

    time_t time = convertToTime(dateString, format);

    printf("Epoch time: %ld\n", time);

    return 0;
}