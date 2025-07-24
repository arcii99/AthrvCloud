//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: mathematical
#include <stdio.h>

// Function to calculate the maximum number of activities that can be done within a given time interval
void maxActivities(int startTime[], int finishTime[], int n) {
    int count = 1; // initialize the count to 1 for the first activity
    int last_finish = finishTime[0]; // initialize the last_finish with the finishing time of the first activity

    // iterate through the remaining activities
    for(int i = 1; i < n; i++) {
        // if the activity start time is greater than or equal to the last finish time
        if(startTime[i] >= last_finish) {
            count++; // increase the count of activities
            last_finish = finishTime[i]; // update the last finish time
        }
    }

    printf("Maximum number of activities that can be done within the given time interval is: %d", count);
}

int main() {
    int startTime[] = {1, 3, 0, 5, 8, 5}; // start time of each activity
    int finishTime[] = {2, 4, 6, 7, 9, 9}; // finish time of each activity
    int n = sizeof(startTime) / sizeof(startTime[0]); // total number of activities

    // sort the activities in increasing order of their finishing time
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(finishTime[i] > finishTime[j]) {
                // swap the finish time
                int temp_finish = finishTime[i];
                finishTime[i] = finishTime[j];
                finishTime[j] = temp_finish;

                // swap the start time
                int temp_start = startTime[i];
                startTime[i] = startTime[j];
                startTime[j] = temp_start;
            }
        }
    }

    // call the maxActivities function to get the maximum number of activities that can be done
    maxActivities(startTime, finishTime, n);

    return 0;
}