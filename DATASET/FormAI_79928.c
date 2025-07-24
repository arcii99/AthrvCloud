//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

struct activity {
    int start;
    int end;
};

int cmp(const void *a, const void *b) {
    struct activity *actA = (struct activity *) a;
    struct activity *actB = (struct activity *) b;
    return actA->end - actB->end;
}

int maxActivities(struct activity activities[], int n) {
    qsort(activities, n, sizeof(struct activity), cmp);
    int i = 0;
    int count = 1;
    for(int j=1; j < n; j++) {
        if(activities[j].start >= activities[i].end) {
            count++;
            i = j;
        }
    }
    return count;
}

int main() {
    struct activity activities[] = {{12,20}, {1,8}, {5,9}, {2,6}, {3,10}, {7,15}};
    int n = sizeof(activities)/sizeof(struct activity);
    int max = maxActivities(activities, n);
    printf("Max number of activities that can be performed simultaneously: %d\n", max);
    return 0;
}