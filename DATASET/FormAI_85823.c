//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Claude Shannon
#include<stdio.h>

// Function to compare two intervals based on their finish time
int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}
 
// Function to find the maximum number of activities that can be performed
void activitySelection(int start[], int finish[], int n)
{
    // Sorting the activities based on their finish time
    qsort(finish, n, sizeof(int), compare);
 
    // Selecting the first activity
    printf("Activities selected: 0 ");
    int i = 0;
 
    // Selecting the next activity with start time greater than the finish time of already selected activity
    for (int j = 1; j < n; j++)
    {
        if (start[j] >= finish[i])
        {
            printf("%d ", j);
            i = j;
        }
    }
}
 
// Driver program to test above function
int main()
{
    int start[] =  {1, 3, 0, 5, 8, 5};
    int finish[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(start)/sizeof(start[0]);
    activitySelection(start, finish, n);
    return 0;
}