//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>

int main() {
    int n; // number of activities
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    // arrays to store activity start and finish times
    int start[n], finish[n];
    printf("Enter the starting and finishing time of each activity (separated by a space):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &start[i], &finish[i]);
    }

    // sort activities in increasing order of finish time
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (finish[i] > finish[j]) {
                int tmp = finish[i];
                finish[i] = finish[j];
                finish[j] = tmp;

                tmp = start[i];
                start[i] = start[j];
                start[j] = tmp;
            }
        }
    }

    // find maximum number of non-overlapping activities
    int count = 1;
    int last_finish = finish[0];
    for (int i = 1; i < n; i++) {
        if (start[i] >= last_finish) {
            count++;
            last_finish = finish[i];
        }
    }

    printf("The maximum number of non-overlapping activities is: %d\n", count);

    return 0;
}