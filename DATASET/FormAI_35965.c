//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EXERCISES 10
#define MIN_SETS 3
#define MAX_SETS 5
#define MIN_REPS 5
#define MAX_REPS 15

int main() {
    srand(time(NULL));  // seed the random number generator
    
    int exercise_count = rand() % MAX_EXERCISES + 1;  // choose a random number of exercises to do
    int total_sets = 0;
    int total_reps = 0;
    
    printf("Today's workout:\n");
    for (int i = 0; i < exercise_count; i++) {
        int sets = rand() % (MAX_SETS - MIN_SETS + 1) + MIN_SETS;  // choose a random number of sets to do for this exercise
        int reps = rand() % (MAX_REPS - MIN_REPS + 1) + MIN_REPS;  // choose a random number of reps to do for each set
        printf("  Exercise %d - %d sets of %d reps\n", i+1, sets, reps);
        total_sets += sets;
        total_reps += (sets * reps);
    }

    printf("\nTotal workout:\n");
    printf("  %d sets\n", total_sets);
    printf("  %d reps\n", total_reps);

    return 0;
}