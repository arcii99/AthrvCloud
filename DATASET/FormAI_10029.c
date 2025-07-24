//FormAI DATASET v1.0 Category: Date and time ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // Initialize random seed with time
    
    // Generate random values for year, month, day, hour, minute and second
    int year = rand() % 100 + 2020;
    int month = rand() % 12 + 1;
    int day = rand() % 31 + 1;
    int hour = rand() % 24;
    int minute = rand() % 60;
    int second = rand() % 60;
    
    // Check if the date and time are valid
    if(day > 28 && month == 2) {
        day = 28; // Set to last day of February
    } else if(day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
        day = 30; // Set to last day of April, June, September, or November
    }
    
    // Store date and time in custom format
    char date[20];
    sprintf(date, "%02d-%02d-%d %02d:%02d:%02d", day, month, year, hour, minute, second);
    
    // Display date and time to user
    printf("The current date and time is: %s\n", date);

    return 0;
}