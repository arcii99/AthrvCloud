//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: modular
#include <stdio.h>

// Function to find the maximum number of activities
void maxActivities(int start[], int finish[], int n)
{
    int i, j;

    printf ("Selected activities are: ");
 
    // The first activity always gets selected
    i = 0;
    printf("%d ", i);
 
    // For the remaining activities
    for (j = 1; j < n; j++)
    {
        // If activity j starts after activity i finishes
        if (start[j] >= finish[i])
        {
            printf ("%d ", j);
            i = j;
        }
    }
}

int main()
{
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start)/sizeof(start[0]);
    
    // Sorting the activities according to their finishing times
    int i, j, temp;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(finish[j] > finish[j+1])
            {
                // Swapping the finishing times
                temp = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = temp;
 
                // Swapping the starting times
                temp = start[j];
                start[j] = start[j+1];
                start[j+1] = temp; 
            }
        }
    }

    maxActivities(start, finish, n);
    return 0;
}