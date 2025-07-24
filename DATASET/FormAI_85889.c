//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int total, goal;
    int count = 0;
    int i;

    printf("Enter your fitness tracker goal: ");
    scanf("%d", &goal);

    printf("Enter the number of days you want to track: ");
    scanf("%d", &total);

    int workouts[total];

    for (i = 0; i < total; i++) {
        printf("Enter your workout for day %d: ", i+1);
        scanf("%d", &workouts[i]);

        if (workouts[i] >= goal) {
            count++;
        }
    }

    printf("You met your goal %d times!\n", count);
    printf("Here's a breakdown of your workouts:\n");

    for (i = 0; i < total; i++) {
        printf("Day %d: %d\n", i+1, workouts[i]);
    }

    return 0;
}