//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <time.h>

int main() {
    
    time_t presentTime;
    struct tm *timeInfo;
    int yearsToAdd;
    
    printf("Welcome to Time Travel Simulator!\n");
    printf("Enter the number of years you want to travel to: ");
    scanf("%d", &yearsToAdd);
    
    presentTime = time(NULL);
    timeInfo = localtime(&presentTime);
    
    timeInfo->tm_year += yearsToAdd;
    time_t newTime = mktime(timeInfo);
    
    printf("You have traveled %d years into the future!\n", yearsToAdd);
    
    printf("Current time before time travel: %s", asctime(timeInfo));
    timeInfo = localtime(&newTime);
    printf("Current time after time travel: %s", asctime(timeInfo));
    
    printf("Thank you for using Time Travel Simulator!\n");
    
    return 0;
}