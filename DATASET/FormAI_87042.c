//FormAI DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>

// Statistical recursive function
float meanRecursive(float arr[], int n)
{
    // Base case
    if (n == 1)
        return arr[0];

    // Recursive case
    return ((n-1)*meanRecursive(arr, n-1) + arr[n-1])/n;
}

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);

    // Error handling
    if(n <= 0)
    {
        printf("Invalid input! Size should be positive.\n");
        return 0;
    }

    float arr[n];
    printf("Enter %d elements of the array : \n",n);

    for(int i = 0; i < n; i++)
    {
        scanf("%f",&arr[i]);
    }

    printf("The mean of the array is : %.2f", meanRecursive(arr, n));
    return 0;
}