//FormAI DATASET v1.0 Category: System boot optimizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MEMORY 1024

void optimize_boot(int num_iterations);

int main()
{
    printf("Starting boot optimization...\n");
    srand(time(NULL));
    int num_iterations = rand() % 100 + 50;
    optimize_boot(num_iterations);
    printf("Boot optimization complete.\n");
    return 0;
}

void optimize_boot(int num_iterations)
{
    int i;
    float total_time = 0;
    for (i = 0; i < num_iterations; i++)
    {
        int start = clock();
        char* memory_block = (char*) malloc(MEMORY * sizeof(char));
        if (memory_block != NULL)
        {
            free(memory_block);
        }
        int end = clock();
        float time_diff = ((float) (end - start)) / CLOCKS_PER_SEC;
        total_time += time_diff;
    }
    float avg_time = total_time / num_iterations;
    printf("Average time to allocate and free memory block: %f seconds\n", avg_time);
}