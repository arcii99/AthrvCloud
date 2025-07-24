//FormAI DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int n, int x) {
    for(int i=0; i<n; i++) {
        if(arr[i] == x)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {3, 6, 91, 12, 8, 43, 32, 9, 10, 65, 22};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 10;
    int index = search(arr, n, x);
    if(index == -1)
        printf("Oh no! We couldn't find %d in the array. :(\n", x);
    else
        printf("We found %d at index %d! WHOA! :D\n", x, index);
    return 0;
}