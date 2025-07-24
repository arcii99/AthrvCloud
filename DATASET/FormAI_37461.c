//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>

struct User {
    char name[50];
    int age;
    double weight;
    double height;
    char gender[10];
};

struct userActivities {
    int day;
    int month;
    int year;
    int steps;
    double caloriesBurned;
};

void printActivity(struct userActivities activity) {
    printf("Activity for %02d/%02d/%04d:\n", activity.day, activity.month, activity.year);
    printf("Steps: %d\n", activity.steps);
    printf("Calories Burned: %lf\n\n", activity.caloriesBurned);
}

int main() {

    struct User user = {"John", 30, 70, 170, "Male"};

    const int numActivities = 7;
    struct userActivities activities[numActivities];

    for (int i = 0; i < numActivities; i++) {
        activities[i].day = i + 1;
        activities[i].month = 9;
        activities[i].year = 2022;
        activities[i].steps = rand() % 10000 + 5000;
        activities[i].caloriesBurned = (user.weight / user.height) * activities[i].steps * 0.05;
    }

    printf("Welcome to Your Fitness Tracker!\n\n");
    printf("User Information\n");
    printf("-----------------\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %lf kg\n", user.weight);
    printf("Height: %lf cm\n", user.height);
    printf("Gender: %s\n\n", user.gender);
    printf("-----------------\n\n");

    printf("Activity for the Week\n");
    printf("--------------------\n\n");

    for (int i = 0; i < numActivities; i++) {
        printActivity(activities[i]);
    }

    return 0;
}