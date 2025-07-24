//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Dennis Ritchie
#include <stdio.h>

/* define function to find index of a target value in a given array */
int search(int arr[], int n, int target){
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target) return mid;
        if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; /* return -1 if target value not found in array */
}

int main(){
    int n, target, result;
    printf("Enter size of array: ");
    scanf("%d", &n); /* read size of array from user */

    int arr[n];
    printf("Enter values of array in ascending order:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]); /* read values of array from user */
    }

    printf("Enter target value to be searched: ");
    scanf("%d", &target); /* read target value from user */

    result = search(arr, n, target); /* call search function */
    if(result == -1) printf("Target value not found in array.\n");
    else printf("Target value found at index %d in array.\n", result);

    return 0;
}