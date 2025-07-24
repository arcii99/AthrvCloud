//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {
    int year;
    printf("Enter the year you would like to travel to: \n");
    scanf("%d", &year);

    if (year < 2021) {
        printf("Sorry, you can't travel back in time. Please choose a year in the future.\n");
        exit(1);
    }

    int age;
    printf("Enter your age: \n");
    scanf("%d", &age);

    int travelAge = age + (year - 2021);

    printf("In %d, you will be %d years old.\n", year, travelAge);

    return 0;
}