//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define struct for user information
typedef struct {
    char name[50];
    int age;
    double height;
    double weight;
} user;

//define struct for fitness tracking data
typedef struct {
    int day;
    int month;
    int year;
    double caloriesBurned;
    double hoursOfSleep;
    double waterConsumed;
    double stepsTaken;
} fitnessData;

//function to print user information
void printUser(user u) {
    printf("Name: %s\n", u.name);
    printf("Age: %d\n", u.age);
    printf("Height: %.2lf\n", u.height);
    printf("Weight: %.2lf\n", u.weight);
}

//function to print fitness data
void printFitnessData(fitnessData f) {
    printf("Date: %d/%d/%d\n", f.day, f.month, f.year);
    printf("Calories Burned: %.2lf\n", f.caloriesBurned);
    printf("Hours of Sleep: %.2lf\n", f.hoursOfSleep);
    printf("Water Consumed: %.2lf\n", f.waterConsumed);
    printf("Steps Taken: %.0lf\n", f.stepsTaken);
}

int main() {
    //initialize user information
    user u;
    strcpy(u.name, "John Doe");
    u.age = 30;
    u.height = 1.8;
    u.weight = 75.0;

    //initialize fitness data for 7 days
    fitnessData f[7];
    f[0].day = 1;
    f[0].month = 1;
    f[0].year = 2021;
    f[0].caloriesBurned = 1500.5;
    f[0].hoursOfSleep = 7.5;
    f[0].waterConsumed = 2000.0;
    f[0].stepsTaken = 10000.0;

    //copy values from previous day for the rest of the days
    for (int i = 1; i < 7; i++) {
        f[i].day = f[i-1].day + 1;
        f[i].month = f[i-1].month;
        f[i].year = f[i-1].year;
        f[i].caloriesBurned = f[i-1].caloriesBurned;
        f[i].hoursOfSleep = f[i-1].hoursOfSleep;
        f[i].waterConsumed = f[i-1].waterConsumed;
        f[i].stepsTaken = f[i-1].stepsTaken;
    }

    //print user information and fitness data for the last 3 days
    printUser(u);
    printf("===========================\n");
    printf("Fitness Data:\n");
    printf("===========================\n");
    for (int i = 4; i < 7; i++) {
        printf("Day %d:\n", i);
        printFitnessData(f[i]);
        printf("===========================\n");
    }

    return 0;
}