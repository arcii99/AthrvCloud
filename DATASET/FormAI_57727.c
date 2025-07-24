//FormAI DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include<stdio.h>

// Function to implement the searching algorithm
int search(int arr[], int n, int x){
    int i;
    for (i = 0; i < n; i++){
        // If element is present in the array
        if (arr[i] == x)
            return i;
    }
    // If element is not present in the array
    return -1;
}

int main(){
    int arr[50], n, x, i, result;
    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    // Get the number to be searched from the user
    printf("Enter the number you want to search: ");
    scanf("%d", &x);
    // Call the search function
    result = search(arr, n, x);
    if (result == -1)
        printf("Number not found in the array.");
    else
        printf("Number %d found at index %d in the array.",x,result);
    return 0;
}