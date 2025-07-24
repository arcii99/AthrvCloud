//FormAI DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>

// define data structure for the array
typedef struct {
    int key;
    int value;
} Data;

// define array of data
Data arr[] = {{1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50}, {6, 60}, {7, 70}, {8, 80}, {9, 90}, {10, 100}};

// recursive binary search function 
int binary_search(Data arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        // If the key is present at the middle 
        if (arr[mid].key == x)
            return mid;
  
        // If the key is smaller than mid, then it can only
        // be present in left subarray
        if (arr[mid].key > x)
            return binary_search(arr, l, mid - 1, x);
  
        // Else the key can only be present in right subarray
        return binary_search(arr, mid + 1, r, x);
    }
  
    // We reach here when element is not present in array
    return -1;
}

int main() {
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 7;

    // call binary search function
    int result = binary_search(arr, 0, n-1, x);

    // print result
    if (result == -1) {
        printf("Element is not present in array.");
    } else {
        printf("Element found at index %d: (%d, %d)", result, arr[result].key, arr[result].value);
    }
  
    return 0;
}