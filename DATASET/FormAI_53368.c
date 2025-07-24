//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: thoughtful
#include <stdio.h>

// function to find maximum number of activities
void printMaxActivities(int start[], int finish[], int n)  
{  
    int i, j;  
    printf ("Selected activities: ");
    
    // Initial activity always gets selected
    i = 0;  
    printf("%d ", i);  
    
    // Consider rest of the activities
    for (j = 1; j < n; j++)  
    {  
        // If the current activity has start time greater than or equal to the finish 
        // time of previously selected activity, then select it
        if (start[j] >= finish[i])  
        {  
            printf ("%d ", j);  
            i = j;  
        }  
    }  
}  

// main function
int main()  
{  
    // array of start times
    int start[] = {1, 3, 0, 5, 8, 5};  
    
    // array of finish times
    int finish[] = {2, 4, 6, 7, 9, 9};  
      
    // Number of activities
    int n = sizeof(start)/sizeof(start[0]);  
    
    // call the max activities function
    printMaxActivities(start, finish, n);  
    
    return 0;  
}