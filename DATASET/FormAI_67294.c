//FormAI DATASET v1.0 Category: Digital signal processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 1000 // number of samples

double x[N]; // input signal
double y[N]; // output signal

// function to calculate the convolution of two signals
void convolution(double *x, double *h, double *y, int n, int m)
{
    int i, j;
    for(i = 0; i < n + m - 1; i++)
    {
        y[i] = 0.0;
        for(j = 0; j < m; j++)
        {
            if(i - j >= 0 && i - j < n)
            {
                y[i] += x[i - j] * h[j];
            }
        }
    }
}

// thread function for convolving the input signal with the filter
void *convolve(void *arg)
{
    int tid = *(int*) arg;
    int chunk_size = N / 4;
    int start = tid * chunk_size;
    int end = (tid + 1) * chunk_size - 1;
    double h[4] = {0.2, 0.4, 0.3, 0.1}; // filter coefficients
    
    convolution(&x[start], h, &y[start], chunk_size, 4);
    
    return NULL;
}

int main()
{
    int i;
    for(i = 0; i < N; i++)
    {
        // generate random input signal
        x[i] = (double)rand() / RAND_MAX; 
    }
    
    pthread_t threads[4];
    int thread_ids[4] = {0, 1, 2, 3};
    
    for(i = 0; i < 4; i++)
    {
        // create threads to perform convolution in parallel
        pthread_create(&threads[i], NULL, convolve, &thread_ids[i]);
    }
    
    for(i = 0; i < 4; i++)
    {
        // wait for threads to finish
        pthread_join(threads[i], NULL);
    }
    
    // print output signal
    for(i = 0; i < N; i++)
    {
        printf("%f\n", y[i]);
    }
    
    return 0;
}