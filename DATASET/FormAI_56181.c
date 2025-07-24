//FormAI DATASET v1.0 Category: Sorting ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_SIZE 100 // Maximum size of array to be sorted
#define MAX_THREADS 5 // Maximum number of threads to be used
#define MAX_QUEUE_SIZE 20 // Maximum size of job queue

/* Data structure to hold the information about a job */
typedef struct {
    int* arr; // Pointer to the array to be sorted
    int left; // Index of the leftmost element of the subarray
    int right; // Index of the rightmost element of the subarray
} job_t;

/* Data structure to hold the information about a thread */
typedef struct {
    pthread_t thread; // The thread object
    int id; // Unique ID of the thread
} thread_t;

/* Global variables */
thread_t threads[MAX_THREADS];
pthread_mutex_t mutex;
pthread_cond_t job_ready;
pthread_cond_t job_done;
job_t job_queue[MAX_QUEUE_SIZE];
int queue_head = 0;
int queue_tail = 0;
int num_jobs = 0;
int num_threads = 0;
int arr[MAX_SIZE];

/* Function to swap two elements in an array */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to partition an array using the last element as pivot */
int partition(int* arr, int left, int right) {
    int i = left - 1;
    int pivot = arr[right];
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

/* Function to perform quicksort on a subarray */
void* quicksort_job(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (num_jobs == 0) { // Wait for a job to be available
            pthread_cond_wait(&job_ready, &mutex);
        }
        job_t job = job_queue[queue_head];
        queue_head = (queue_head + 1) % MAX_QUEUE_SIZE;
        num_jobs--;
        pthread_mutex_unlock(&mutex);

        if (job.left < job.right) {
            int pivot_index = partition(job.arr, job.left, job.right);
            job_t left_job = {job.arr, job.left, pivot_index - 1};
            job_t right_job = {job.arr, pivot_index + 1, job.right};
            
            pthread_mutex_lock(&mutex);
            while (num_jobs == MAX_QUEUE_SIZE - 2) { // Wait if job queue is full
                pthread_cond_wait(&job_done, &mutex);
            }
            job_queue[queue_tail] = left_job;
            queue_tail = (queue_tail + 1) % MAX_QUEUE_SIZE;
            num_jobs++;
            pthread_cond_signal(&job_ready);
            pthread_mutex_unlock(&mutex);
            
            quicksort_job(&right_job);
        }
        else { // Subarray has length 1 or 0, so this job is done
            pthread_mutex_lock(&mutex);
            num_threads--;
            if (num_threads == 0 && num_jobs == 0) { // All jobs done, signal main thread
                pthread_cond_signal(&job_ready);
            }
            else {
                pthread_cond_signal(&job_done);
            }
            pthread_mutex_unlock(&mutex);
        }
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    
    // Generate random array to be sorted
    printf("Unsorted array: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 1000;
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Initialize mutex and condition variables
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&job_ready, NULL);
    pthread_cond_init(&job_done, NULL);
    
    // Create threads
    for (int i = 0; i < MAX_THREADS; i++) {
        threads[i].id = i;
        pthread_create(&threads[i].thread, NULL, quicksort_job, NULL);
    }
    num_threads = MAX_THREADS;
    
    // Add initial job to job queue
    job_t init_job = {arr, 0, MAX_SIZE - 1};
    pthread_mutex_lock(&mutex);
    job_queue[queue_tail] = init_job;
    queue_tail = (queue_tail + 1) % MAX_QUEUE_SIZE;
    num_jobs++;
    pthread_cond_signal(&job_ready);
    pthread_mutex_unlock(&mutex);
    
    // Wait for all jobs to finish
    pthread_mutex_lock(&mutex);
    while (num_threads > 0 || num_jobs > 0) {
        pthread_cond_wait(&job_ready, &mutex);
    }
    pthread_mutex_unlock(&mutex);
    
    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Destroy mutex and condition variables
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&job_ready);
    pthread_cond_destroy(&job_done);
    
    return 0;
}