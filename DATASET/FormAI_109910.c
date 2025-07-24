//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct workout {
    char exercise[50];
    int reps;
    int sets;
    int weight;
};

int main() {
    int n;
    printf("Enter the number of workouts: ");
    scanf("%d", &n);

    struct workout *w = (struct workout*)malloc(n * sizeof(struct workout));
    char temp[50];

    for (int i = 0; i < n; i++) {
        printf("\nEnter workout details for workout %d: \n", i+1);
        printf("Enter exercise: ");
        scanf("%s", temp);
        strcpy(w[i].exercise, temp);
        printf("Enter reps: ");
        scanf("%d", &w[i].reps);
        printf("Enter sets: ");
        scanf("%d", &w[i].sets);
        printf("Enter weight: ");
        scanf("%d", &w[i].weight);
    }

    printf("\n\nWorkout Logs: \n\n");

    for (int i = 0; i < n; i++) {
        printf("Workout %d: %s, %d sets, %d reps, %d lbs\n", i+1, w[i].exercise, w[i].sets, w[i].reps, w[i].weight);
        printf("Total Volume for workout %d: %d lbs\n\n", i+1, w[i].sets * w[i].reps * w[i].weight);
    }

    free(w);

    return 0;
}