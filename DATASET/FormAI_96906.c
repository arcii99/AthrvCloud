//FormAI DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>

int main()
{
    int arr[10] = {5, 9, 12, 18, 27, 36, 45, 57, 68, 76}; // array of integers
    int n = 10; // size of array
    int searchNumber = 27; // value to search in array
    int i, flag = 0; // flag to check if the value is found or not

    printf("Array elements are: ");
    for(i=0; i<n; i++) // to print array elements
        printf("%d ", arr[i]);

    for(i=0; i<n; i++) // loop to check if the value is present in array
    {
        if(arr[i] == searchNumber)
        {
            flag = 1; //setting the flag
            break; //exit the loop
        }
    }
    if(flag == 1) //if value is found
        printf("\n%d is found at position %d", searchNumber, i+1);
    else //if value is not found
        printf("\n%d is not found in the array", searchNumber);

    return 0; //end of program
}