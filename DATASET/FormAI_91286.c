//FormAI DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include<stdio.h>

/* Function to search for an element in a given array */
int linearSearch(int arr[],int n, int x){

    int i;

    /*
     * Traverse through the array, comparing each element
     * with the element to be searched.
     */
    for(i=0;i<n;i++){
        if(arr[i] == x){
            return i;
        }
    }

    // If the element is not found, return -1.
    return -1;
}

int main(){

    int arr[50], n, i, x, pos;

    printf("Enter the size of the array (max 50): ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    // Call the linearSearch function
    pos = linearSearch(arr, n, x);

    if(pos == -1){
        printf("Element not found!");
    }
    else{
        printf("Element found at position %d", pos+1);
    }

    return 0;
}