//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Alan Touring
#include <stdio.h>
#include <time.h>

int main(){
    time_t currentTime;
    struct tm * currentDate;
    char date[64];

    time(&currentTime);
    currentDate = localtime(&currentTime);
    
    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("The current date and time is: %s", asctime(currentDate));

    printf("\nEnter the amount of days you want to travel through time: ");
    int days;
    scanf("%d", &days);

    currentDate->tm_mday += days;
    mktime(currentDate);
    
    strftime(date, sizeof(date), "%A, %B %d %Y", currentDate);
    
    printf("\nYou have traveled %d days through time and have arrived on %s.\n\n", days, date);

    printf("Thank you for using the Time Travel Simulator!\n");

    return 0;
}