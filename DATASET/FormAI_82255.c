//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

int arr[100];
int key, size, result = -1;

void *binary_search(void *param) {
    int start = *((int *)param);
    int end = start + size/4;
    for (int i = start; i < end; i++) {
        if (arr[i] == key) {
            result = i;
            break;
        }
    }
    return NULL;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter array elements in sorted order: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter key to search: ");
    scanf("%d", &key);
    
    size = n;
    pthread_t threads[4];
    int start[4] = {0, size/4, size/2, 3*size/4};
    
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, binary_search, &start[i]);
    }
    
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }
    
    if (result != -1) {
        printf("Element is present at index: %d\n", result);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}