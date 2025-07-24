//FormAI DATASET v1.0 Category: Searching algorithm ; Style: satisfied
#include <stdio.h>

int binary_search(int arr[], int n, int x){
    int start = 0;
    int end = n - 1;
    while(start <= end){
        int mid = (start + end) / 2; // Find mid index
        if(arr[mid] == x) // If element is found then return index
            return mid;
        
        if(arr[mid] < x) // If element is greater than mid element
            start = mid + 1;
        else // If element is smaller than mid element
            end = mid - 1;
    }
    return -1; // If element is not found then return -1
}

int main(){
    int n;
    printf("Enter the size of Array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of Array:\n");
    for(int i=0; i<n; ++i) // Read elements of array
        scanf("%d", &arr[i]);
        
    int x;
    printf("Enter the element to search: ");
    scanf("%d", &x);
    
    int index = binary_search(arr, n, x); // Call binary search function
    if(index != -1) // If element is found then print index
        printf("%d is present at index %d\n", x, index);
    else // If element is not found
        printf("Element not found\n");
    return 0;
}