//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t now = time(NULL); // Get current time
    struct tm *timeinfo = localtime(&now); // Convert to struct tm
    
    printf("Welcome to the C Time Travel Simulator!\n");
    
    char travel;
    printf("Do you want to travel to the past or the future? (p/f): ");
    scanf("%c", &travel);
    
    if (travel == 'p') {
        printf("How many years back in time do you want to go? ");
    } else if (travel == 'f') {
        printf("How many years into the future do you want to go? ");
    } else {
        printf("Invalid input. Please try again.\n");
        return 0;
    }
    
    int years;
    scanf("%d", &years);
    
    timeinfo->tm_year = timeinfo->tm_year + years; // Adjust year
    time_t travel_time = mktime(timeinfo); // Convert back to time_t
    
    printf("You have traveled %d years into the %s!\n", abs(years), travel == 'p' ? "past" : "future");
    printf("The date and time is now: %s", asctime(localtime(&travel_time)));
    
    return 0;
}