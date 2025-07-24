//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int* arr, size, i, sum = 0;
    float avg;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    arr = (int*) malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    printf("Enter elements of array:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    avg = (float) sum / size;
    printf("Average = %.2f\n", avg);
    free(arr);
    return 0;
}