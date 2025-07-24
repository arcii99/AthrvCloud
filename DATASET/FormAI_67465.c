//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: detailed
#include <stdio.h>

// Function to sort the intervals based on the end time
void sortIntervals(int intervals[][2], int n) {
    // Bubble sort implementation
    int i, j, temp;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(intervals[j][1] > intervals[j+1][1]) {
                // Swap the intervals
                temp = intervals[j][0];
                intervals[j][0] = intervals[j+1][0];
                intervals[j+1][0] = temp;

                temp = intervals[j][1];
                intervals[j][1] = intervals[j+1][1];
                intervals[j+1][1] = temp;
            }
        }
    }
}

// Function to find the maximum number of meetings that can be scheduled
void maxMeetings(int start[], int end[], int n) {
    int intervals[n][2]; // Array to store the intervals
    int i, count = 1;

    // Store the intervals in an array
    for(i=0; i<n; i++) {
        intervals[i][0] = start[i];
        intervals[i][1] = end[i];
    }

    // Sort the intervals based on the end time
    sortIntervals(intervals, n);

    // Select the meetings one by one and count them
    int currentEnd = intervals[0][1];
    for(i=1; i<n; i++) {
        if(intervals[i][0] > currentEnd) {
            count++;
            currentEnd = intervals[i][1];
        }
    }

    // Print the maximum number of meetings that can be scheduled
    printf("Maximum number of meetings that can be scheduled: %d", count);
}

int main() {
    // Example usage of maxMeetings function
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start)/sizeof(start[0]);
    maxMeetings(start, end, n);

    return 0;
}