//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: brave
#include <stdio.h>

#define MAX_ACTIVITIES 1000

// function to perform greedy activity selection
void activity_selection(int start[], int finish[], int n) {
    int i, j, count = 1;

    // select the first activity
    int last_finish = finish[0];

    // iterate through remaining activities
    for (i = 1; i < n; i++) {
        // check if current activity start time is greater than or equal to last finish time
        if (start[i] >= last_finish) {
            // select current activity
            count++;
            last_finish = finish[i];
        }
    }

    printf("Maximum number of activities that can be selected = %d\n", count);
}

int main() {
    int n, i;
    int start[MAX_ACTIVITIES], finish[MAX_ACTIVITIES];

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    printf("Enter the start and finish times of the activities:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &start[i], &finish[i]);
    }

    // perform activity selection by greedy algorithm
    activity_selection(start, finish, n);

    return 0;
}