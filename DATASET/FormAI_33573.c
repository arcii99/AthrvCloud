//FormAI DATASET v1.0 Category: Searching algorithm ; Style: ephemeral
// Ephemeral C Searching Algorithm Example
// By Chatbot

#include <stdio.h>

int main()
{
    int arr[] = {11, 23, 42, 56, 62, 71, 89, 97};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 62; // number to be searched
    int left = 0; 
    int right = n - 1; 
    int mid; 

    while (left <= right) {
        mid = (left + right) / 2; 

        if (arr[mid] == x) { // match found
            printf("\n%d Found at index %d", x, mid);
            return 0;
        }
        else if (arr[mid] > x) { // search in left half
            right = mid - 1; 
        }
        else { // search in right half
            left = mid + 1; 
        }
    }
    printf("\n%d Not found in the array", x);
    return 0;
}