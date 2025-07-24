//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include <stdio.h>

// Structure to represent an activity
struct activity
{
    int start, finish;
};

// Function to print the maximum number of activities that can be performed
void printMaxActivities(struct activity activities[], int n)
{
    int i, j;

    // Sort activities based on finish time
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (activities[j].finish > activities[j+1].finish)
            {
                struct activity temp = activities[j];
                activities[j] = activities[j+1];
                activities[j+1] = temp;
            }
        }
    }

    // Print activities
    printf("The following activities are selected: \n");

    // The first activity is always selected
    i = 0;
    printf("(%d, %d) ", activities[i].start, activities[i].finish);

    // Consider all remaining activities
    for (j = 1; j < n; j++)
    {
        // If this activity has a start time greater than or equal to
        // the finish time of the previously selected activity,
        // then select it
        if (activities[j].start >= activities[i].finish)
        {
            printf("(%d, %d) ", activities[j].start, activities[j].finish);
            i = j;
        }
    }
}

int main()
{
    struct activity activities[] = {{1, 3}, {2, 5}, {3, 7}, {4, 9}, {5, 12}, {6, 14}, {7, 16}, {8, 18}, {9, 20}, {10, 22}};
    int n = sizeof(activities)/sizeof(activities[0]);

    printMaxActivities(activities, n);

    return 0;
}