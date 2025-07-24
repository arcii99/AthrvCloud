//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Cryptic
#include <stdio.h>

#define MAX_WORKOUTS 5

struct workout {
    char name[20];
    int reps;
    int sets;
    float weight;
} workouts[MAX_WORKOUTS];

int main(void) {
    int i;
    int num_workouts;
    float total_weight = 0.0;
    
    printf("Enter the number of workouts you completed today: ");
    scanf("%d", &num_workouts);

    // Collect workout data
    for (i = 0; i < num_workouts; i++) {
        printf("\n\nWorkout #%d:\n", i+1);

        printf("- Name: ");
        scanf("%s", workouts[i].name);

        printf("- Reps: ");
        scanf("%d", &workouts[i].reps);

        printf("- Sets: ");
        scanf("%d", &workouts[i].sets);

        printf("- Weight: ");
        scanf("%f", &workouts[i].weight);

        total_weight += workouts[i].weight;
    }

    // Print workout summary
    printf("\n\nWorkout Summary:\n\n");
    printf("Name\tReps\tSets\tWeight\n");
    printf("----\t----\t----\t------\n");
    for (i = 0; i < num_workouts; i++) {
        printf("%s\t%d\t%d\t%.2f\n", workouts[i].name, workouts[i].reps, workouts[i].sets, workouts[i].weight);
    }
    printf("\nTotal Weight Lifted: %.2f\n", total_weight);

    return 0;
}