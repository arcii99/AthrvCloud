//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>

int cyberSearch(int array[], int low, int high, int element){
    //Binary Searching Algorithm with Cyberpunk style
    if(high >= low){
        int mid = low + (high - low)/2;
        if(array[mid] == element)
            return mid;
        if(array[mid] > element)
            return cyberSearch(array, low, mid-1, element);
        return cyberSearch(array, mid+1, high, element);
    }
    return -1;
}

int main(){
    int n, i, ele, res;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter %d elements into the array: ", n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the element you wish to search: ");
    scanf("%d", &ele);

    res = cyberSearch(arr, 0, n-1, ele);

    if(res == -1)
        printf("\nElement is not present in the array. Stay alert!");
    else
        printf("\nElement is present at position %d. Stay frosty!", res+1);
    
    return 0;
}