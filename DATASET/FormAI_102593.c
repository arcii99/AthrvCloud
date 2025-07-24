//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bucket_sort(int array[], int n);

int main() {

    int n, i, arr[MAX_SIZE];
    
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bucket_sort(arr, n);

    printf("Sorted elements:\n");
    for(i = 0; i < n; i++)
        printf("%d\n", arr[i]);

    return 0;
}

void bucket_sort(int array[], int n) {

    int i, j, count[MAX_SIZE];
    memset(count, 0, sizeof(count));

    for(i = 0; i < n; i++)
        ++count[array[i]];

    for(i = 0, j = 0; i < MAX_SIZE; i++)
        for(; count[i] > 0; --count[i])
            array[j++] = i;
}