//FormAI DATASET v1.0 Category: Database Indexing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

struct Index {
    int key;
    int offset;
};

int binarySearch(struct Index arr[], int l, int r, int key) {
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid].key == key)
            return arr[mid].offset;
        else if(arr[mid].key < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the number of records: ");
    scanf("%d", &n);

    struct Index index[n];
    printf("Enter the records in key-offset format:\n");
    for(int i = 0; i < n; i++)
        scanf("%d %d", &index[i].key, &index[i].offset);

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    int offset = binarySearch(index, 0, n - 1, key);
    if(offset == -1)
        printf("Record not found\n");
    else
        printf("Record found at offset: %d\n", offset);

    return 0;
}