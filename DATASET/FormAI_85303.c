//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Function to find maximum sum subarray using Greedy Approach
int maxSum(int arr[], int n)
{
    int currSum = 0, maxSum = INT_MIN, startIndex = 0, endIndex = 0;

    for(int i=0; i<n; i++)
    {
        currSum += arr[i];

        if(currSum > maxSum)
        {
            maxSum = currSum;
            endIndex = i;
        }
        if(currSum < 0)
        {
            currSum = 0;
            startIndex = i+1;
        }
    }

    printf("The maximum sum subarray is: ");
    for(int i=startIndex; i<=endIndex; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return maxSum;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The given array is: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int maxSubarraySum = maxSum(arr, n);

    printf("The maximum sum of subarray is %d\n", maxSubarraySum);

    return 0;
}