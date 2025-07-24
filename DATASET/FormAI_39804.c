//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int cyberSearch(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
 
    while (low <= high) {
        int mid = (low + high) / 2;
 
        if (arr[mid] == x)
            return mid;
 
        if (arr[mid] < x)
            low = mid + 1;
 
        else
            high = mid - 1;
    }
 
    return -1;
}
 
int main(void)
{
    int arr[] = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 35;
    int index = cyberSearch(arr, n, x);

    if (index != -1)
        printf("The index of %d is: %d\n", x, index);
    else
        printf("The value %d is not present in the array.", x);
    
    return 0;
}