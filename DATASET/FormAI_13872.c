//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define LIMIT 1000

int arr[LIMIT];

int search(int val, int left, int right) {
    if (left == right) {
        if (arr[left] == val) return left;
        else return -1;
    }
    else {
        int mid = (left + right) / 2;
        if (arr[mid] == val) return mid;
        else if (arr[mid] > val) return search(val, left, mid - 1);
        else return search(val, mid + 1, right);
    }
}

int main() {
    for (int i = 0; i < LIMIT; i++) {
        arr[i] = rand() % 100;
    }

    int val = rand() % 100;
    int res = search(val, 0, LIMIT - 1);

    if (res != -1) {
        printf("The element %d was found at index %d\n", val, res);
    }
    else {
        printf("The element %d was not found in the array\n", val);
    }

    return 0;
}