//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct activity {
    int start;
    int end;
};

int compare(const void* a, const void* b) {
    const struct activity* x = (const struct activity*) a;
    const struct activity* y = (const struct activity*) b;
    return (x->end - y->end);
}

void printMaxActivities(struct activity arr[], int n) {
    qsort(arr, n, sizeof(struct activity), compare);

    int i = 0, j;
    printf("Selected activities: ");
    printf("(%d,%d) ", arr[i].start, arr[i].end);

    for(j=1; j<n; j++) {
        if(arr[j].start >= arr[i].end) {
            printf("(%d,%d) ", arr[j].start, arr[j].end);
            i = j;
        }
    }
}

int main() {
    struct activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printMaxActivities(arr, n);
    return 0;
}