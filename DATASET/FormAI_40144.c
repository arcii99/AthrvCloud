//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>

// A structure to represent an activity
struct Activity {
    int start, finish;
};

// Function to print all activities that are compatible with current activity
void printCompatible(struct Activity activities[], int n, int i) {
    int j;
    printf("Compatible activities for activity %d: ", i + 1);
    for (j = i + 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            printf("%d ", j + 1);
        }
    }
    printf("\n");
}

// Function to implement the Greedy Activity Selection Algorithm
void greedActivitySelect(struct Activity activities[], int n) {
    int i, j;
    // Sort activities according to their finish time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (activities[j].finish < activities[i].finish) {
                struct Activity temp = activities[j];
                activities[j] = activities[i];
                activities[i] = temp;
            }
        }
    }
    // Select activities greedily
    printf("Selected activities: 1 ");
    int prevFinish = activities[0].finish;
    for (i = 1; i < n; i++) {
        if (activities[i].start >= prevFinish) {
            printf("%d ", i + 1);
            prevFinish = activities[i].finish;
        }
    }
    printf("\n");
    //print all compatible activities for each activity
    for (i = 0; i < n - 1; i++) {
        printCompatible(activities, n, i);
    }
}

int main() {
    struct Activity activities[] = { {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
                                    {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14} };
    int n = sizeof(activities)/sizeof(activities[0]);
    greedActivitySelect(activities, n);
    return 0;
}