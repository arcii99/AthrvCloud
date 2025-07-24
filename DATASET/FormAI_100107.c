//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// The structure to store the activity data.
struct Activity {
    int start;
    int finish;
};

// The function to compare the activity finish time.
int CompareActivity(const void *a, const void *b) {
    return ((struct Activity*)a)->finish - ((struct Activity*)b)->finish;
}

// The function to find the maximum number of activities that can be scheduled.
int MaxActivities(struct Activity activities[], int count) {
    int i, j, maxCount = 0;
    qsort(activities, count, sizeof(activities[0]), CompareActivity);
    for (i = 0, j = 0; i < count; i++) {
        if (activities[i].start >= activities[j].finish) {
            maxCount++;
            j = i;
        }
    }
    return maxCount;
}

int main() {
    int i, count;
    printf("Enter the number of activities: ");
    scanf("%d", &count);
    struct Activity activities[count];
    for (i = 0; i < count; i++) {
        printf("Enter the start time and finish time for activity %d: ", i + 1);
        scanf("%d%d", &activities[i].start, &activities[i].finish);
    }
    printf("The maximum number of activities that can be scheduled is: %d\n", MaxActivities(activities, count));
    return 0;
}