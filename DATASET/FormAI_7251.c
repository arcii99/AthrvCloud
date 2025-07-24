//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //initialize random seed

    int pushupCount = rand() % 50; //generate random pushup count between 0-49
    int situpCount = rand() % 50; //generate random situp count between 0-49
    int squatCount = rand() % 50; //generate random squat count between 0-49

    float pushupCaloriesBurned = pushupCount * 0.25; //calculate calories burned per pushup
    float situpCaloriesBurned = situpCount * 0.15; //calculate calories burned per situp
    float squatCaloriesBurned = squatCount * 0.35; //calculate calories burned per squat

    float totalCaloriesBurned = pushupCaloriesBurned + situpCaloriesBurned + squatCaloriesBurned; //calculate total calories burned

    printf("FITNESS TRACKER\n");
    printf("---------------\n");
    printf("Today you did %d pushups, %d situps, and %d squats.\n", pushupCount, situpCount, squatCount);
    printf("You burned %.2f calories doing pushups, %.2f calories doing situps, and %.2f calories doing squats.\n", pushupCaloriesBurned, situpCaloriesBurned, squatCaloriesBurned);
    printf("In total, you burned %.2f calories today.\n", totalCaloriesBurned);

    if(totalCaloriesBurned > 500){
        printf("Great job! You met your daily fitness goal of burning 500 calories or more!\n");
    } else {
        printf("Keep going! You still need to burn %.2f more calories to meet your daily fitness goal.\n", 500 - totalCaloriesBurned);
    }

    return 0;
}