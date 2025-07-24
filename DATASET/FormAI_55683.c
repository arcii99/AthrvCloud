//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
    int total_days = 7; // total number of days in a week
    int max_tasks = 3;  // maximum number of tasks you can complete in a day
    int tasks[7][3];    // tasks array to store the tasks for each day

    printf("Enter the tasks for each day (separated by a space):\n");

    // loop through each day
    for (int i = 0; i < total_days; i++) {
        printf("Day %d: ", i+1);

        // loop through each task
        for (int j = 0; j < max_tasks; j++) {
            scanf("%d", &tasks[i][j]);
        }
    }

    // calculate the total points for each day
    int points[7];
    for (int i = 0; i < total_days; i++) {
        points[i] = 0;

        // loop through each task and add its points
        for (int j = 0; j < max_tasks; j++) {
            points[i] += tasks[i][j];
        }
    }

    // find the day with the most points
    int max_points = points[0];
    int best_day = 1;
    for (int i = 1; i < total_days; i++) {
        if (points[i] > max_points) {
            max_points = points[i];
            best_day = i+1;
        }
    }

    printf("The best day to complete tasks is Day %d with %d total points.\n", best_day, max_points);

    return 0;
}