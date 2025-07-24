//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>

int main() {
    int days, i, j, calories = 0;
    printf("Enter number of days to track: ");
    scanf("%d", &days);

    int food[days][3], exercise[days][3], burned[days][3], intake[days][3];

    for(i = 0; i < days; i++) {
        printf("\nEnter food intake for day %d\n", i+1);
        for(j = 0; j < 3; j++) {
            printf("Enter calories for meal %d: ", j+1);
            scanf("%d", &food[i][j]);
            intake[i][j] += food[i][j];
        }

        printf("\nEnter exercise for day %d\n", i+1);
        for(j = 0; j < 3; j++) {
            printf("Enter calories burned during exercise %d: ", j+1);
            scanf("%d", &exercise[i][j]);
            burned[i][j] += exercise[i][j];
        }
    }

    for(i = 0; i < days; i++) {
        printf("\nDay %d:\n", i+1);
        printf("Intake: %d\n", intake[i][0] + intake[i][1] + intake[i][2]);
        printf("Burned: %d\n", burned[i][0] + burned[i][1] + burned[i][2]);
        calories += (intake[i][0] + intake[i][1] + intake[i][2]) - (burned[i][0] + burned[i][1] + burned[i][2]);
        printf("Net calories: %d\n", calories);
    }

    return 0;
}