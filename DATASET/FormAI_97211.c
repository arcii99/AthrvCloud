//FormAI DATASET v1.0 Category: Fractal Generation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <pthread.h>

#define WINDOW_SIZE 1000
#define MAX_ITERATIONS 2000

typedef struct
{
    double x, y;
} ComplexNumber;

typedef struct
{
    int start;
    int end;
    pthread_t thread;
} ThreadData;

bool isMandelbrot(ComplexNumber c)
{
    ComplexNumber z;
    z.x = 0;
    z.y = 0;

    for (int i = 0; i < MAX_ITERATIONS; i++)
    {
        double x_temp = (z.x * z.x) - (z.y * z.y) + c.x;
        double y_temp = 2 * z.x * z.y + c.y;
        z.x = x_temp;
        z.y = y_temp;

        if ((z.x * z.x) + (z.y * z.y) > 4)
        {
            return false;
        }
    }
    return true;
}

void *computeMandelbrot(void *arg)
{
    ThreadData *td = (ThreadData*)arg;

    for (int i = td->start; i < td->end; i++)
    {
        double x = (double)i / WINDOW_SIZE;
        for (int j = 0; j < WINDOW_SIZE; j++)
        {
            double y = (double)j / WINDOW_SIZE;
            ComplexNumber c;
            c.x = (x * 3.5) - 2.5;
            c.y = (y * 2.0) - 1.0;

            bool mandelbrot = isMandelbrot(c);

            if (mandelbrot)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[4];
    ThreadData threadData[4];

    int workloadPerThread = WINDOW_SIZE / 4;
    for (int i = 0; i < 4; i++)
    {
        threadData[i].start = i * workloadPerThread;
        threadData[i].end = (i + 1) * workloadPerThread;
        pthread_create(&threadData[i].thread, NULL, computeMandelbrot, &threadData[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        pthread_join(threadData[i].thread, NULL);
    }

    return 0;
}