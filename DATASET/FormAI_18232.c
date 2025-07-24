//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int calories = 0;
    int steps = 0;
    int distance = 0;
    int heart_rate = 0;
    int hours_slept = 0;

    srand(time(0));
    calories = rand() % 2000 + 500;
    steps = rand() % 5000 + 1000;
    distance = rand() % 5 + 1;
    heart_rate = rand() % 70 + 60;
    hours_slept = rand() % 4 + 4;
    
    printf("Welcome to the Cyberpunk Fitness Tracker!\n");
    printf("You burned %d calories today\n", calories);
    printf("You took %d steps\n", steps);
    printf("You walked %d miles\n", distance);
    printf("Your average heart rate was %d bpm\n", heart_rate);
    printf("You slept for %d hours last night\n", hours_slept);

    if(calories > 1500 && steps > 3000 && distance >= 3 && heart_rate > 70 && hours_slept >= 6) {
        printf("Congrats! You did a great job today. Keep up the good work!\n");
    } else {
        printf("You didn't hit all of your goals today. Try again tomorrow\n");
    }

    return 0;
}