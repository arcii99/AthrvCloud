//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to travel through time
void time_travel(int years) {
    // get current time
    time_t current_time;
    time(&current_time);
    
    // calculate new time
    struct tm* new_time = localtime(&current_time);
    new_time->tm_year += years;
    time_t new_time_t = mktime(new_time);
    
    // print out new date and time
    printf("You have traveled %d years into the future.\n", years);
    printf("New date and time: %s", ctime(&new_time_t));
}

int main() {
    int choice;
    int years;
    
    printf("Welcome to the Time Travel Simulator!\n");
    
    // prompt user for input
    while (1) {
        printf("Where would you like to go? (Enter 1 for future, 2 for past, or 3 to exit)\n");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("How many years into the future would you like to travel?\n");
            scanf("%d", &years);
            time_travel(years);
        } else if (choice == 2) {
            printf("How many years into the past would you like to travel?\n");
            scanf("%d", &years);
            time_travel(-years);
        } else if (choice == 3) {
            printf("Thank you for using the Time Travel Simulator!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}