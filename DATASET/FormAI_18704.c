//FormAI DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>

//function to search the array for the given element
int search(int arr[], int n, int x) {
    int i;
    for(i=0;i<n;i++) {
        if(arr[i]==x) {
            return i; //return the index of the element if found
        }
    }
    return -1; //return -1 if element is not found
}

int main() {
    int arr[10] = {5,12,7,21,3,19,9,18,15,6};
    int n = 10; //size of array
    int x; //element to be searched
    int pos; //position of element in array
    
    printf("Enter the element to be searched: ");
    scanf("%d", &x);
    
    pos = search(arr, n, x);
    
    if(pos!=-1) {
        printf("%d is present at index %d in the array.", x, pos);
    }
    else {
        printf("%d is not present in the array.", x);
    }
    
    return 0;
}