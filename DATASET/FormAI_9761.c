//FormAI DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include<stdio.h>

//The following function performs linear search on an array of integers
//It returns the index of the element if it is present in the array, else it returns -1
int linear_search(int arr[], int n, int x) {
    int i;
    for(i=0; i<n; i++) {
        if(arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, i, x, pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n); //Inputting the number of elements in the array
    int arr[n];
    printf("Enter the elements of the array: ");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]); //Inputting the elements of the array
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &x); //Inputting the element to be searched
    pos = linear_search(arr, n, x); //Calling the linear_search function to search for the element
    if(pos == -1) {
        printf("The element is not present in the array!");
    }
    else {
        printf("The element is present at index %d", pos);
    }
    return 0;
}