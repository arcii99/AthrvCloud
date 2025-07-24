//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: peaceful
#include <stdio.h>

struct Activity {
    int start;
    int end;
};

typedef struct Activity Activity;

int compare(const void* a, const void* b) {
    return ((Activity*)a)->end - ((Activity*)b)->end;
}

void printMaxActivities(Activity activities[], int n) {
    qsort(activities, n, sizeof(Activity), compare);
    int i = 0, j;
    printf("Selected activities: ");
    printf("(%d,%d) ", activities[i].start, activities[i].end);
    for(j = 1; j < n; j++) {
        if(activities[j].start >= activities[i].end) {
            printf("(%d,%d) ", activities[j].start, activities[j].end);
            i = j;
        }
    }
}

int main() {
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);
    Activity activities[n];
    printf("Enter start and end times of activities:\n");
    for(int i = 0; i < n; i++)
        scanf("%d %d", &activities[i].start, &activities[i].end);
    printMaxActivities(activities, n);
    return 0;
}