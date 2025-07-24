//FormAI DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>

//function to perform linear search
int linear_search(int arr[], int n, int x){
    int i;
    for (i = 0; i < n; i++){
        if (arr[i] == x)
            return i; //element found, return its position
    }
    return -1; //element not found in the array
}

//function to perform binary search
int binary_search(int arr[], int l, int r, int x){
    while (l <= r){
        int mid = l + (r - l) / 2;
        //check if x is present at mid
        if (arr[mid] == x)
            return mid;

        //if x greater, ignore left half
        if (arr[mid] < x)
            l = mid + 1;
        //if x is smaller, ignore right half
        else
            r = mid - 1;
    }
    //element not found in the array
    return -1;
}

int main(){
    int arr[] = {12, 23, 34, 45, 56, 67, 78, 89, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 56; //element to be searched

    //perform linear search
    int pos = linear_search(arr, n, x);
    if (pos == -1) //element not found
        printf("Element %d not found in the array!\n", x);
    else //element found at position pos
        printf("Element %d found at position %d\n", x, pos+1);

    //perform binary search
    int l = 0, r = n - 1;
    pos = binary_search(arr, l, r, x);
    if (pos == -1) //element not found
        printf("Element %d not found in the array!\n", x);
    else //element found at position pos
        printf("Element %d found at position %d\n", x, pos+1);

    return 0;
}