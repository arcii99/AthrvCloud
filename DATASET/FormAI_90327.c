//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int today_workout_time = 0;
    int total_workout_time = 0;
    int days_completed = 0;
    int goal = 30;
    srand(time(0));
    
    printf("Welcome to your C Fitness Tracker!\n\n");
    printf("Your workout goal is %d minutes per day.\n", goal);
    printf("Let's get started!\n\n");
    
    while (days_completed < 7) {
        printf("Day %d - Workout Time: %d minutes\n", days_completed+1, today_workout_time);
        
        // generate a random workout time for the day
        int workout_time = rand() % 61;
        printf("You worked out for %d minutes today.\n", workout_time);
        
        // update today's workout time and total workout time
        today_workout_time += workout_time;
        total_workout_time += workout_time;
        
        if (today_workout_time >= goal) {
            printf("Congratulations, you achieved your goal for today!\n");
        }
        else {
            int remaining_time = goal - today_workout_time;
            printf("You need to workout for %d more minutes to reach your goal for the day.\n", remaining_time);
        }
        
        printf("Total Workout Time: %d minutes\n\n", total_workout_time);
        today_workout_time = 0;
        days_completed++;
    }
    
    printf("Congratulations, you completed a full week of workouts!\n");
    printf("Total Workout Time: %d minutes\n", total_workout_time);
    
    return 0;
}