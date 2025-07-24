//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

int main()
{
    int* array = (int*) malloc(SIZE * sizeof(int));

    srand(time(NULL));

    for(int i=0; i<SIZE; i++)
    {
        array[i] = rand()%1000;
    }

    int sum = 0;

    for(int i=0; i<SIZE; i++)
    {
        if(array[i]%2 == 0)
        {
            sum += array[i];
        }
    }

    printf("Sum of even numbers in array is %d\n", sum);

    free(array);

    return 0;
}