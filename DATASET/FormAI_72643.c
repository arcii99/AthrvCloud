//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: satisfied
#include <stdio.h>

#define MAX_ACTIVITIES 100

struct activity {
    int start, end;
};

int compare_activities(const void *a, const void *b) {
    struct activity *act_a = (struct activity*) a;
    struct activity *act_b = (struct activity*) b;
    return act_a->end - act_b->end;
}

void select_activities(struct activity activities[], int n) {
    qsort(activities, n, sizeof(struct activity), compare_activities);
    int selected[MAX_ACTIVITIES];
    int count = 0, last = -1;
    for (int i = 0; i < n; ++i) {
        if (activities[i].start >= last) {
            selected[count++] = i;
            last = activities[i].end;
        }
    }
    printf("Selected activities: ");
    for (int i = 0; i < count; ++i) {
        printf("(%d,%d) ", activities[selected[i]].start, activities[selected[i]].end);
    }
}

int main() {
    struct activity activities[] = {
        {1, 3},
        {5, 7},
        {2, 4},
        {6, 8},
        {8, 10},
        {9, 11},
        {11, 13},
        {12, 14},
        {3, 5},
        {4, 6}
    };
    int n = sizeof(activities) / sizeof(struct activity);
    select_activities(activities, n);
    return 0;
}