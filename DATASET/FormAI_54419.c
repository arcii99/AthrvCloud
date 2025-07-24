//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: grateful
#include <stdio.h>

// Define a structure to hold an activity and its start/end times
struct Activity {
    int start;
    int end;
};

// Function to sort activities in ascending order of end time
int compare(const void *a, const void *b) {
    struct Activity *activity1 = (struct Activity*) a;
    struct Activity *activity2 = (struct Activity*) b;

    return (activity1->end - activity2->end);
}

// Function to find the maximum number of activities that can be performed
int maxActivities(struct Activity activities[], int n) {
    // Sort activities by their end time
    qsort(activities, n, sizeof(struct Activity), compare);

    int count = 1; // At least one activity can be done
    int prevEnd = activities[0].end;

    // Check remaining activities to see which ones can be done
    for (int i = 1; i < n; i++) {
        // If current activity starts after previous activity ends, it can be done
        if (activities[i].start >= prevEnd) {
            count++;
            prevEnd = activities[i].end;
        }
    }

    return count;
}

int main() {
    printf("Welcome to the Activity Selection Program!\n");

    // Define an array of activities
    struct Activity activities[] = {
        { 1, 4 },
        { 3, 5 },
        { 0, 6 },
        { 5, 7 },
        { 3, 8 },
        { 5, 9 },
        { 6, 10 },
        { 8, 11 },
        { 8, 12 },
        { 2, 13 },
        { 12, 14 }
    };
    int n = sizeof(activities) / sizeof(activities[0]);

    // Calculate the maximum number of activities that can be performed
    int max = maxActivities(activities, n);

    printf("The maximum number of activities that can be performed is %d.\n", max);

    return 0;
}