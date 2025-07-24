//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>

int main() {
    // Program to schedule tasks on a processor with minimum end time

    int n, i, j;
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    int start[n], end[n];
    printf("Enter start and end time of each task:\n");
    for(i=0; i<n; i++) {
        scanf("%d %d", &start[i], &end[i]);
    }

    // Sort tasks by end time in ascending order
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(end[i] > end[j]) {
                int temp = end[i];
                end[i] = end[j];
                end[j] = temp;

                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }

    int count = 1;
    int current = end[0];
    printf("\nScheduled Tasks: (%d, %d)", start[0], end[0]);
    for(i=1; i<n; i++) {
        if(start[i] >= current) {
            count++;
            current = end[i];
            printf(", (%d, %d)", start[i], end[i]);
        }
    }

    printf("\nTotal number of tasks scheduled: %d\n", count);

    return 0;
}