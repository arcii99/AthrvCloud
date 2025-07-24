//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: light-weight
#include <stdio.h>

int main() {
    int currentTime = 2021;             // set current year
    int userChoice, yearsTraveled;

    printf(" ------- Time Travel Simulator -------\n");
    printf("Enter 1 to travel to the future, 2 to travel to the past: ");
    scanf("%d", &userChoice);
    printf("Enter number of years to travel: ");
    scanf("%d", &yearsTraveled);

    if(userChoice == 1) {               // if user wants to travel to the future
        printf("You are traveling to the year %d...\n", currentTime + yearsTraveled);
        printf("Welcome to the future!\n");
    }
    else if(userChoice == 2) {          // if user wants to travel to the past
        printf("You are traveling to the year %d...\n", currentTime - yearsTraveled);
        printf("Welcome to the past!\n");
    }
    else {
        printf("Invalid choice. Please enter 1 or 2.\n");
    }
    return 0;
}