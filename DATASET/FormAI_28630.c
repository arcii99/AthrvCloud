//FormAI DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>

int linear_search(int arr[], int n, int x) {
    int i;
    for(i=0;i<n;i++) {
        if(arr[i]==x) {
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int n, int x) {
    int low=0, high=n-1, mid;
    while(low<=high) {
        mid = low+(high-low)/2;
        if(arr[mid]==x) {
            return mid;
        } else if(arr[mid]>x) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return -1;
}

int interpolation_search(int arr[], int n, int x) {
    int low=0, high=n-1, pos;
    while(low<=high && x>=arr[low] && x<=arr[high]) {
        pos = low + ((double)(high-low)/(arr[high]-arr[low]))*(x-arr[low]);

        if(arr[pos]==x) {
            return pos;
        } else if(arr[pos]<x) {
            low = pos+1;
        } else {
            high = pos-1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1,3,5,7,9,11,13,15,17,19};
    int n = sizeof(arr)/sizeof(int);

    int x1 = 9; //Element to search
    printf("Linear Search Result: %d\n", linear_search(arr, n, x1));

    int x2 = 15; //Element to search
    printf("Binary Search Result: %d\n", binary_search(arr, n, x2));

    int x3 = 5; //Element to search
    printf("Interpolation Search Result: %d\n", interpolation_search(arr, n, x3));

    return 0;
}