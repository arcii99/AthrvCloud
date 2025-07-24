//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
#include <stdio.h>

/* Ken Thompson style unique searching algorithm */

int search(int a[], int low, int high, int key) {
    if (low == high) {
        if (a[low] == key)
            return low;
        return -1;
    }
    int mid = (low + high) / 2;
    if (a[mid] < a[high]) {
        if (a[mid] < key && key <= a[high])
            return search(a, mid + 1, high, key);
        return search(a, low, mid, key);
    }
    else {
        if (a[low] <= key && key < a[mid])
            return search(a, low, mid, key);
        return search(a, mid + 1, high, key);
    }
}

int main() {
    int a[] = { 4, 5, 6, 7, 1, 2, 3 };
    int key = 2, n = sizeof(a) / sizeof(a[0]), index;

    index = search(a, 0, n - 1, key);

    if (index != -1)
        printf("%d found at index %d\n", key, index);
    else
        printf("%d not found\n", key);

    return 0;
}