//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: light-weight
#include <stdio.h>

// Structure for activity
struct Activity {
    int start, finish;
};

// Function that takes an array of activities
// along with its size as input and
// returns the maximum number of activities
// that can be performed by a single person
int getMaxActivities(struct Activity arr[], int n) {
    int i, j, maxActivities = 1;

    // Sort the array according to finish time
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (arr[j + 1].finish < arr[j].finish) {
                struct Activity temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Pick the first activity as the first activity
    // that is performed by a single person
    int lastFinishTime = arr[0].finish;

    // Check for the rest of the activities
    for (i = 1; i < n; i++) {
        if (arr[i].start >= lastFinishTime) {
            maxActivities++;
            lastFinishTime = arr[i].finish;
        }
    }

    return maxActivities;
}

int main() {
    // Initialize the activities array
    struct Activity arr[] = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Get the maximum number of activities
    int maxActivities = getMaxActivities(arr, n);

    printf("Maximum number of activities: %d\n", maxActivities);

    return 0;
}