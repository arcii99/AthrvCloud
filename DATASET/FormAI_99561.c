//FormAI DATASET v1.0 Category: Matrix operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 4  // size of matrices

int A[N][N], B[N][N], C[N][N], D[N][N];  // matrices
int num_threads = 4;  // number of threads to use

// thread function to perform matrix addition
void *matrix_addition(void *arg)
{
    int thread_num = *(int *)arg;

    // divide the work among the threads
    int chunk_size = N / num_threads;
    int start = thread_num * chunk_size;
    int end = start + chunk_size;

    // perform matrix addition
    for (int i = start; i < end; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    pthread_exit(NULL);
}

// thread function to perform matrix multiplication
void *matrix_multiplication(void *arg)
{
    int thread_num = *(int *)arg;

    // divide the work among the threads
    int chunk_size = N / num_threads;
    int start = thread_num * chunk_size;
    int end = start + chunk_size;

    // perform matrix multiplication
    for (int i = start; i < end; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            D[i][j] = sum;
        }
    }

    pthread_exit(NULL);
}

int main()
{
    // fill matrices A and B with random values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // create threads for matrix addition
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        int *thread_num = malloc(sizeof(int));
        *thread_num = i;
        pthread_create(&threads[i], NULL, matrix_addition, (void *)thread_num);
    }

    // wait for threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // print result of matrix addition
    printf("C = A + B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // create threads for matrix multiplication
    for (int i = 0; i < num_threads; i++) {
        int *thread_num = malloc(sizeof(int));
        *thread_num = i;
        pthread_create(&threads[i], NULL, matrix_multiplication, (void *)thread_num);
    }

    // wait for threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // print result of matrix multiplication
    printf("\nD = A * B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }

    return 0;
}