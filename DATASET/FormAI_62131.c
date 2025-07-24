//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
#include <stdio.h>

int main() {
    printf("Welcome to the time travel simulator!\n");
    
    int year = 2022;
    printf("The current year is %d.\n", year);
    
    char answer;
    printf("Do you want to travel back in time? (y/n) ");
    scanf("%c", &answer);
    
    if (answer == 'y') {
        int travelYear;
        printf("Enter a year to travel back to: ");
        scanf("%d", &travelYear);
        
        if (travelYear >= year) {
            printf("Sorry, time travel can only go back in time!\n");
        } else {
            printf("Travelling back to %d...\n", travelYear);
            
            int i;
            for (i = year; i >= travelYear; i--) {
                printf("Year: %d\n", i);
            }
            
            printf("Arrived at %d! Hope you enjoyed the trip.\n", travelYear);
        }
    } else if (answer == 'n') {
        printf("Okay, maybe next time when you're feeling more adventurous.\n");
    } else {
        printf("Invalid input, try again.\n");
    }
    
    return 0;
}