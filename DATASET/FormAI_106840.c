//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// function to simulate time travel
char* timeTravel(int years) {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year += years;
    mktime(timeinfo);

    char* date = asctime(timeinfo);
    date[strlen(date) - 1] = '\0'; // remove \n from end of string
    return date;
}

// function to handle user input and print result of time travel
void handleInput() {
    int years = 0;
    printf("Enter number of years to travel: ");
    scanf("%d", &years);

    char* date = timeTravel(years);
    printf("You have travelled %d years into the future.\nDate is now: %s\n", years, date);
}

// main function
int main() {
    handleInput();
    return 0;
}