//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>

struct activity 
{ 
    int start, finish; 
};

int compare(const void* a, const void* b) 
{ 
    return (((struct activity*)a)->finish - ((struct activity*)b)->finish); 
} 

void selectActivities(struct activity arr[], int n) 
{ 
    qsort(arr, n, sizeof(struct activity), compare); 
    int i = 0, j; 
    printf("Selected activities: (%d,%d) ", arr[i].start, arr[i].finish); 
    for (j = 1; j < n; j++) 
    { 
        if (arr[j].start >= arr[i].finish) 
        { 
            printf("(%d,%d) ", arr[j].start, arr[j].finish); 
            i = j; 
        } 
    } 
} 

int main() 
{ 
    int n,i;
    printf("Enter number of activities: ");
    scanf("%d",&n);
    struct activity arr[n];
    for(i=0;i<n;i++)
    {
        printf("Enter start and finish time of activity %d: ",i+1);
        scanf("%d%d",&arr[i].start,&arr[i].finish);
    }
    selectActivities(arr, n); 
    return 0; 
}