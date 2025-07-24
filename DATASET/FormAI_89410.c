//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: romantic
#include <stdio.h>
#include <time.h>

int main() {

    time_t currentTime, startTime, endTime;
    struct tm *currentDate, *startDate, *endDate;
    char currentMonth[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char startMonth[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char endMonth[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int currentDay, currentYear, startDay, startYear, endDay, endYear;

    // Get current date and time
    time(&currentTime);
    currentDate = localtime(&currentTime);
    currentDay = currentDate->tm_mday;
    currentYear = currentDate->tm_year + 1900;

    printf("Welcome to the Time Travel Simulator!\n\n");

    printf("Enter the date you want to start your journey: (mm/dd/yyyy) ");
    scanf("%d/%d/%d", &startDate->tm_mon, &startDay, &startYear);

    startTime = mktime(startDate);
    startDate = localtime(&startTime);

    printf("Enter the date you want to end your journey: (mm/dd/yyyy) ");
    scanf("%d/%d/%d", &endDate->tm_mon, &endDay, &endYear);

    endTime = mktime(endDate);
    endDate = localtime(&endTime);

    printf("\n\nYou will be traveling from %s %d, %d to %s %d, %d.\n\n", startMonth[startDate->tm_mon], startDay, startYear, endMonth[endDate->tm_mon], endDay, endYear);

    printf("Do you want to know what the weather is like on your travel dates?(y/n) ");
    char choice;
    scanf(" %c", &choice);

    if(choice == 'y') {
        printf("\n\nSorry, our weather prediction system is currently under maintenance.\n\n");
    }
    else {
        printf("\n\nOkay, have a safe journey!\n\n");
    }

    return 0;

}