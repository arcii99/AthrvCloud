//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>

//function to find the maximum number of activities that can be performed
void activitySelection(int start[], int finish[], int n) {
    int i, j;
    printf("Selected Activities:\n");
    //first activity is always selected
    i = 0;
    printf("%d ", i);
    //for remaining activities
    for (j = 1; j < n; j++) {
        //if the start time of the current activity is greater than or equal to the finish of the previously selected activity
        if (start[j] >= finish[i]) {
            printf("%d ", j);
            i = j;
        }
    }
    printf("\n");
}

//driver function
int main() {
    //array of starting times
    int start[] = {1, 3, 0, 5, 8, 5};
    //array of finish times
    int finish[] = {2, 4, 6, 7, 9, 9};
    //number of activities
    int n = sizeof(start) / sizeof(start[0]);
    
    //sort the finish time array in ascending order
    int i, j, temp1, temp2;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (finish[i] > finish[j]) {
                temp1 = finish[i];
                temp2 = start[i];
                finish[i] = finish[j];
                start[i] = start[j];
                finish[j] = temp1;
                start[j] = temp2;
            }
        }
    }
    
    activitySelection(start, finish, n);
    return 0;
}