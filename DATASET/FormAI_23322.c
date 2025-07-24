//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Cryptic
#include <stdio.h>

int main() {
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 60;
    int low = 0, high = n-1;

    while (low <= high) {
        int mid = (low + high)/2;
        if (arr[mid] == key) {
            printf("Key found at index %d\n", mid);
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else if (arr[mid] > key) {
            high = mid - 1;
        }
    }
    return 0;
}