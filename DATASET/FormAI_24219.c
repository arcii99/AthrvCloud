//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

/* Function to compare two items */
int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/* Function to find the maximum number of intervals that can be scheduled */
int maximum_intervals(int start_time[], int end_time[], int n) {
    // Sort the end times
    qsort(end_time, n, sizeof(int), cmpfunc);
    
    int max_intervals = 1;
    int current_end_time = end_time[0];
    
    // Check if the start time of next interval is after the current end time
    for(int i=1; i<n; i++) {
        if(start_time[i]>current_end_time) {
            max_intervals++;
            current_end_time = end_time[i];
        }
    }
    
    return max_intervals;
}

int main()
{
    int start_time[] = {1, 3, 0, 5, 8, 5};
    int end_time[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start_time)/sizeof(start_time[0]);
    
    int max_intervals = maximum_intervals(start_time, end_time, n);
    printf("The maximum number of intervals that can be scheduled are: %d", max_intervals);
    
    return 0;
}