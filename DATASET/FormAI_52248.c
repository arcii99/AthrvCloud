//FormAI DATASET v1.0 Category: Graph representation ; Style: complex
#include<stdio.h>

void printGraph(int arr[], int n)
{
    //Set maximum value to find largest element in the array
    int maxValue = arr[0];
    
    //Loop to find largest element in the array
    int i;
    for(i=1;i<n;i++)
    {
        if(arr[i]>maxValue)
        {
            maxValue = arr[i];
        }
    }
    
    //Loop to print graph
    int j;
    for(i=maxValue;i>=0;i--)
    {
        printf("%d ",i);
        for(j=0;j<n;j++)
        {
            if(arr[j]>=i)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    //Print horizontal axis
    printf("  ");
    for(i=0;i<n;i++)
    {
        printf("%d ",i+1);
    }
    printf("\n");
}

int main()
{
    //Define array and array size
    int arr[]={7,5,2,6,3,1,4};
    int n =sizeof(arr)/sizeof(arr[0]);
    
    //Print graph using function
    printGraph(arr,n);
    
    return 0;
}