//FormAI DATASET v1.0 Category: Math exercise ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000000

// Generate an array of random numbers between 1 and 1000.
void generate_numbers(int *numbers, int count)
{
    srand((unsigned) time(NULL));
    for (int i = 0; i < count; i++)
    {
        numbers[i] = rand() % 1000 + 1;
    }
}

// Find the max number in the array using linear search.
int max_linear_search(int *numbers, int count)
{
    int max = numbers[0];
    for (int i = 1; i < count; i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }
    return max;
}

// Find the max number in the array using binary search.
int max_binary_search(int *numbers, int start, int end)
{
    if (start == end)
    {
        return numbers[start];
    }
    int mid = (start + end) / 2;
    int left_max = max_binary_search(numbers, start, mid);
    int right_max = max_binary_search(numbers, mid + 1, end);
    return (left_max > right_max) ? left_max : right_max;
}

int main()
{
    int numbers[MAX_NUMBERS];
    int count = 10000;

    generate_numbers(numbers, count);

    clock_t start_time = clock();
    int max_linear = max_linear_search(numbers, count);
    clock_t end_time = clock();
    double time_linear = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    start_time = clock();
    int max_binary = max_binary_search(numbers, 0, count - 1);
    end_time = clock();
    double time_binary = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    printf("Linear Search:\n");
    printf("Max: %d\n", max_linear);
    printf("Time: %f seconds\n", time_linear);

    printf("\nBinary Search:\n");
    printf("Max: %d\n", max_binary);
    printf("Time: %f seconds\n", time_binary);

    return 0;
}