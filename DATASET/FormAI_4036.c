//FormAI DATASET v1.0 Category: Searching algorithm ; Style: modular
#include <stdio.h>

//Function to search for an element in an array
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

//Function to print the result of the search
void printResult(int result)
{
    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", result);
}

//Main function
int main()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };  //Sample array
    int n = sizeof(arr) / sizeof(arr[0]); //Size of array
    int x; //Element to search for

    //Input element from user
    printf("Enter element to search: ");
    scanf("%d", &x);

    //Call search function and print result
    int result = search(arr, n, x);
    printResult(result);

    return 0;
}