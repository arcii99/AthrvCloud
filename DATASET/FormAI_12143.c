//FormAI DATASET v1.0 Category: Sorting ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 10

int array[ARRAY_SIZE] = {4, 2, 8, 1, 6, 5, 3, 7, 9, 0};
int sorted_array[ARRAY_SIZE];

typedef struct {
    int start;
    int end;
}sortParams;

void *sort(void *args)
{
    sortParams *params = (sortParams *) args;

    int i, j, temp;
    for (i = params->start; i <= params->end; i++)
        for (j = i + 1; j <= params->end; j++)
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }

    pthread_exit(0);
}

int main()
{
    pthread_t thread1, thread2;
    sortParams params1 = {0, ARRAY_SIZE / 2 - 1};
    sortParams params2 = {ARRAY_SIZE / 2, ARRAY_SIZE - 1};

    pthread_create(&thread1, NULL, sort, &params1);
    pthread_create(&thread2, NULL, sort, &params2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    int i, j, k;
    i = j = k = 0;
    while (i < ARRAY_SIZE / 2 && j < ARRAY_SIZE - ARRAY_SIZE / 2)
    {
        if (array[i] <= array[j + ARRAY_SIZE / 2])
        {
            sorted_array[k] = array[i];
            i++;
        }
        else
        {
            sorted_array[k] = array[j + ARRAY_SIZE / 2];
            j++;
        }
        k++;
    }

    while (i < ARRAY_SIZE / 2)
    {
        sorted_array[k] = array[i];
        i++;
        k++;
    }

    while (j < ARRAY_SIZE - ARRAY_SIZE / 2)
    {
        sorted_array[k] = array[j + ARRAY_SIZE / 2];
        j++;
        k++;
    }

    printf("Original Array: ");
    for (i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", array[i]);

    printf("\n\nSorted Array: ");
    for (i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", sorted_array[i]);

    return 0;
}