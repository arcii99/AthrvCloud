//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

struct activities {
    int start, finish;
};

void greedyActivitySelector(struct activities* arr, int n) {
    int i = 0;
    printf("(%d, %d)", arr[i].start, arr[i].finish);

    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            printf(", (%d, %d)", arr[j].start, arr[j].finish);
            i = j;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    struct activities* arr = (struct activities*)malloc(n * sizeof(struct activities));

    printf("Enter the start and finish time for each activity: \n");

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &arr[i].start, &arr[i].finish);
    }

    printf("The activities selected are: ");
    greedyActivitySelector(arr, n);

    return 0;
}