//FormAI DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>

// Function to search for an element in an array using the Medieval Search Algorithm
int medieval_search(int arr[], int size, int target)
{
    int left = 0, right = size - 1, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
 
        if (arr[mid] == target) // If element is found in the middle
        {
            printf("The target was found in the middle of the castle, in room %d.\n", mid+1);
            return mid;
        }
        else if (arr[mid] < target) // If element is greater than the middle element
        {
            left = mid + 1;
            printf("The target was not found in the middle, so our knights searched deeper into the castle.\n");
        }
        else // If element is smaller than the middle element
        {
            right = mid - 1;
            printf("The target was not found in the middle, so our knights searched deeper into the castle.\n");
        }
    }
 
    printf("The target could not be found in this castle. Our knights fought bravely but the search was unsuccessful. \n");
    return -1;
}
 
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 40;

    printf("Our knights are searching the castle for the target...\n");
    medieval_search(arr, size, target);

    return 0;
}