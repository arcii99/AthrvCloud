//FormAI DATASET v1.0 Category: Digital signal processing ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

#define BUFFER_SIZE 64
#define WINDOW_SIZE 8

float recursive_filter(float* buffer, int index)
{
    if(index < WINDOW_SIZE)
    {
        return buffer[index];
    }
    else
    {
        float y = 0.5 * (buffer[index] + buffer[index - WINDOW_SIZE]);
        buffer[index] = y;
        return recursive_filter(buffer, index - 1);
    }
}

int main()
{
    float buffer[BUFFER_SIZE] = {0};

    //Generate a test signal
    for(int i = 0; i < BUFFER_SIZE; i++)
    {
        buffer[i] = (float)rand() / (float)RAND_MAX;
    }

    //Apply recursive filter
    for(int i = 0; i < BUFFER_SIZE; i++)
    {
        float y = recursive_filter(buffer, i);
        printf("%f\n", y);
    }

    return 0;
}