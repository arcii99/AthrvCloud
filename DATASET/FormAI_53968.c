//FormAI DATASET v1.0 Category: Searching algorithm ; Style: secure
#include <stdio.h>

int secure_search(int arr[], int n, int x) {

    int min = 0, max = n-1, mid;

    while(min <= max) {

        mid = (min+max)/2;

        if(arr[mid] == x) {

            return mid;

        } else if(arr[mid] < x) {

            min = mid+1;

        } else {

            max = mid-1;

        }

    }

    return -1;
}

int main() {

    int arr[10] = {0,2,4,6,8,10,12,14,16,18};
    int n = 10, x = 12;

    int result = secure_search(arr, n, x);

    if(result == -1) {

        printf("%d not found in array.\n", x);

    } else {

        printf("%d found at index %d in array.\n", x, result);

    }

    return 0;
}