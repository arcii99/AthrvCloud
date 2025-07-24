//FormAI DATASET v1.0 Category: Memory management ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

int* allocate_memory(int size)
{
    int* ptr;

    ptr = (int*)malloc(size * sizeof(int));

    return ptr;
}

void deallocate_memory(int* ptr)
{
    free(ptr);
}

int main()
{
    int size, i;
    int* arr;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = allocate_memory(size);

    printf("Enter the elements of the array: ");
    for(i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    printf("The elements of the array are: ");
    for(i=0; i<size; i++){
        printf("%d ", arr[i]);
    }

    deallocate_memory(arr);

    return 0;
}