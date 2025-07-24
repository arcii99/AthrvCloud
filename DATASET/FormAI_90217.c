//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

struct activity {
   int start;
   int finish;
};

int cmp(const void *a, const void *b) {
    return ((struct activity *)a)->finish - ((struct activity *)b)->finish;
}

void printMaxActivities(struct activity arr[], int n) {
    qsort(arr, n, sizeof(arr[0]), cmp);
    int i = 0, j;
    printf("Selected activities: (%d, %d)\n", arr[i].start, arr[i].finish);
    for (j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            printf("(%d, %d)\n", arr[j].start, arr[j].finish);
            i = j;
        }
    }
}

int main() {
    struct activity arr[] = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 9}, {5, 9},
        {6, 10}, {8, 11}, {8, 12}, {2, 14}, {12, 16}
    };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Total activities: %d\n", n);
    printMaxActivities(arr, n);
    return 0;
}