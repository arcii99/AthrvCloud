//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate random number between 1000 and 5000 for calories burned
int generateCalories() {
    int calories;
    calories = rand() % (5000 - 1000 + 1) + 1000;
    return calories;
}

int main() {
    //Intialize Variables
    int caloriesBurned[7];
    int totalCalories = 0;
    int i;

    //Seed random number generator
    srand(time(NULL));

    //Loop to generate and store calories burned for each day of the week
    for (i = 0; i < 7; i++) {
        caloriesBurned[i] = generateCalories();
    }

    //Loop to calculate total calories burned for the week
    for (i = 0; i < 7; i++) {
        totalCalories += caloriesBurned[i];
    }

    //Print results
    printf("Calories burned for each day of the week:\n");
    printf("Monday: %d\n", caloriesBurned[0]);
    printf("Tuesday: %d\n", caloriesBurned[1]);
    printf("Wednesday: %d\n", caloriesBurned[2]);
    printf("Thursday: %d\n", caloriesBurned[3]);
    printf("Friday: %d\n", caloriesBurned[4]);
    printf("Saturday: %d\n", caloriesBurned[5]);
    printf("Sunday: %d\n", caloriesBurned[6]);
    printf("Total calories burned for the week: %d", totalCalories);

    return 0;
}