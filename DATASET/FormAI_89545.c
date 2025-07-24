//FormAI DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdio.h>

//Function to implement searching algorithm
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        //If element found, return its position
        if (arr[i] == x)
            return i;
    }
    //If element not found, return -1
    return -1;
}

int main()
{
    printf("Welcome to the Searching Algorithm Example Program!\n");
    
    int arr[100], n, x, pos;
    
    printf("Enter the number of elements in the array (maximum 100): ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search in the array: ");
    scanf("%d", &x);

    pos = search(arr, n, x);

    if(pos == -1)
        printf("\nElement not found in the array\n");
    else
        printf("\nElement found at position %d\n", pos+1);

    return 0;
}