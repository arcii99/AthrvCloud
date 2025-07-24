//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 10    //number of threads to be created
#define MAX_BUFFER_SIZE 50000000    //50 MB buffer size
#define TIME_DIFF(tv1, tv2) ((tv2.tv_sec - tv1.tv_sec) * 1000.0 + (tv2.tv_usec - tv1.tv_usec) / 1000.0)    //calculate time difference between two timeval structs

struct thread_data {
    int thread_id;    //thread identification number
    char* buffer;    //buffer allocated for each thread
    int buffer_size;    //size of the buffer allocated
    int num_iterations;    //number of iterations each thread will run
};

void *test_speed(void *threadarg) {
    struct timeval start_time, end_time;
    struct thread_data *my_data;
    my_data = (struct thread_data *) threadarg;
    int i;

    for(i=0; i<my_data->num_iterations; i++) {
        gettimeofday(&start_time, NULL);
        write(STDOUT_FILENO, my_data->buffer, my_data->buffer_size);    //write buffer to stdout
        gettimeofday(&end_time, NULL);
        double time_taken = TIME_DIFF(start_time, end_time);
        printf("Thread %d, iteration %d: %f millisecs for %d bytes\n", my_data->thread_id, i+1, time_taken, my_data->buffer_size);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, i, buffer_size_per_thread, remainder;
    char* buffer = (char*) malloc(MAX_BUFFER_SIZE);    //allocate 50MB buffer
    struct thread_data thread_data_array[NUM_THREADS];

    buffer_size_per_thread = MAX_BUFFER_SIZE / NUM_THREADS;
    remainder = MAX_BUFFER_SIZE % NUM_THREADS;

    //initialize thread data array
    for(i=0; i<NUM_THREADS; i++) {
        thread_data_array[i].thread_id = i;
        thread_data_array[i].buffer = buffer + i*buffer_size_per_thread;

        if(i == (NUM_THREADS - 1)) {
            thread_data_array[i].buffer_size = buffer_size_per_thread + remainder;
        }
        else {
            thread_data_array[i].buffer_size = buffer_size_per_thread;
        }

        thread_data_array[i].num_iterations = 3;    //each thread will run 3 iterations
    }

    //create threads
    for(i=0; i<NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, test_speed, (void *)&thread_data_array[i]);
        if(rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    //wait for threads to finish execution
    for(i=0; i<NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if(rc) {
            printf("Error: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    free(buffer);
    pthread_exit(NULL);
}