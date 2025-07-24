//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include <stdio.h>

// Function implementing the greedy algorithm to find the maximum number of non-overlapping intervals
void maximumNonOverlappingIntervals(int start[], int end[], int n) {
    int i, j;
 
    // Sort the intervals based on their ending times
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(end[i] > end[j]) {
                int temp = end[i];
                end[i] = end[j];
                end[j] = temp;
                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }
        
    int count = 1;
    int last = end[0];
 
    // Select the maximum number of non-overlapping intervals
    for(i = 1; i < n; i++) {
        if(start[i] >= last) {
            count++;
            last = end[i];
        }
    }
 
    printf("Maximum number of non-overlapping intervals is %d\n", count);
}
 
int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start)/sizeof(start[0]);
    
    // Call the greedy algorithm function to find the maximum number of non-overlapping intervals
    maximumNonOverlappingIntervals(start, end, n);
 
    return 0;
}