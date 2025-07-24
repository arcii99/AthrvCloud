//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    printf("Welcome to the Time Travel Simulator\n");
    printf("Enter year to go back in time: ");
    int year;
    scanf("%d", &year);
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);
    printf("Current Year: %d\n", currentTime->tm_year + 1900);
    printf("Travelling back in time...\n");
    if(currentTime->tm_year + 1900 < year){
        printf("Cannot travel to the future\n");
        return 0;
    }
    printf("Year travelled back: %d\n", year);
    printf("Calculating time difference...\n");

    int currentYear = currentTime->tm_year + 1900;
    int yearsDiff = currentYear - year;

    printf("Time difference: %d years\n", yearsDiff);
    printf("Time travelling...\n");

    int i;
    for(i = currentYear; i >= year; i--){
        printf("Year: %d\n", i);
        sleep(1); // To simulate time travelling
    }

    printf("You have arrived in %d!\n", year);
    return 0;
}