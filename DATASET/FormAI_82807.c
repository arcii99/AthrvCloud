//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    int exerciseCount = 0;
    float caloriesBurned = 0.0;
    char* activity;
    srand(time(NULL));
    
    printf("------------------------\n");
    printf("|  C FITNESS TRACKER   |\n");
    printf("------------------------\n\n");
    printf("Let's start tracking your workout!\n\n");
    
    while (1) {
        printf("Enter the activity you completed (-1 to exit): ");
        scanf("%s", activity);
        
        if (strcmp(activity, "-1") == 0) {
            break;
        }
        
        int minutes = rand() % 60 + 30;
        float calories = rand() % 200 + 100;
        
        printf("You completed %d minutes of %s and burned %.2f calories!\n\n", minutes, activity, calories);
        
        exerciseCount++;
        caloriesBurned += calories;
    }
    
    printf("You finished %d workout sessions and burned a total of %.2f calories.\n", exerciseCount, caloriesBurned);
    
    return 0;
}