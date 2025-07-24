//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: interoperable
#include <stdio.h>

// function to compare two intervals based on their start times
int cmp(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

// function to find the maximum number of intervals that can be scheduled
int maxIntervalScheduling(int** intervals, int n) {
    // sort the intervals in non-decreasing order of their start times
    qsort(intervals, n, sizeof(int*), cmp);

    int count = 1;    // stores the count of scheduled intervals
    int lastEnd = intervals[0][1];

    // consider all intervals in sorted order
    for (int i = 1; i < n; ++i) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // if the current interval doesn't overlap with the previous one
        if (start >= lastEnd) {
            // schedule this interval
            ++count;
            lastEnd = end;
        }
    }

    return count;
}

int main() {
    // input array of intervals (each interval is an array of two integers)
    int* arr[] = {
        (int[]) {1, 4},
        (int[]) {3, 5},
        (int[]) {0, 6},
        (int[]) {5, 7},
        (int[]) {3, 8},
        (int[]) {5, 9},
        (int[]) {6, 10},
        (int[]) {8, 11},
        (int[]) {8, 12},
        (int[]) {2, 13}
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum number of intervals that can be scheduled: %d\n",
            maxIntervalScheduling(arr, n));

    return 0;
}