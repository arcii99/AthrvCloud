//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: scientific
#include<stdio.h>

// Function to perform activity selection
void ActivitySelection(int s[], int f[], int n)
{
    int i, j;
 
    printf ("Selected activities:\n");
 
    // The first activity is always selected
    i = 0;
    printf("%d ", i);
 
    // Consider all activities one by one
    for (j = 1; j < n; j++)
    {
        // If this activity has start time greater than or
        // equal to the finish time of previously selected
        // activity, then select it
        if (s[j] >= f[i])
        {
            printf ("%d ", j);
            i = j;
        }
    }
}
 
int main()
{
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);

    // Sorting the activities based on finish times
    int i, j, temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(f[j]>f[j+1]){
                temp = f[j];
                f[j] = f[j+1];
                f[j+1] = temp;

                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
 
    ActivitySelection(s, f, n);
    return 0;
}