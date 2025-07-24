//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: ephemeral
#include <stdio.h>

// Function to perform greedy activity selection
void activitySelection(int start[], int finish[], int n)
{
    int i, j;
 
    // The first activity is always selected
    i = 0;
    printf("Activity #%d - Start: %d  Finish: %d\n", i+1, start[i], finish[i]);
 
    // Consider rest of the activities
    for (j = 1; j < n; j++)
    {
        // If this activity has start time greater than or
        // equal to the finish time of previously selected
        // activity, then select it
        if (start[j] >= finish[i])
        {
            printf("Activity #%d - Start: %d  Finish: %d\n", j+1, start[j], finish[j]);
            i = j;
        }
    }
}

int main()
{
    // Test case
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start)/sizeof(start[0]);

    // Sort the activities based on their finish time
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - 1; j++)
        {
            if (finish[j] > finish[j+1])
            {
                int temp = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = temp;

                temp = start[j];
                start[j] = start[j+1];
                start[j+1] = temp;
            }
        }
    }

    printf("Selected Activities: \n");
    activitySelection(start, finish, n);

    return 0;
}