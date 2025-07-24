//FormAI DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/mman.h>

#define NUMBER_OF_THREADS 2
#define BUFFER_SIZE 10

typedef struct {
    int buffer[BUFFER_SIZE];
    sem_t *mutex;
    sem_t *empty;
    sem_t *full;
    int in;
    int out;
} bounded_buffer;

void *producer(void *arg)
{
    bounded_buffer *bb = (bounded_buffer*) arg;
    int i;

    for (i = 0; i < BUFFER_SIZE*2; i++) {
        sem_wait(bb->empty);
        sem_wait(bb->mutex);

        bb->buffer[bb->in] = i;
        bb->in = (bb->in + 1) % BUFFER_SIZE;

        sem_post(bb->mutex);
        sem_post(bb->full);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg)
{
    bounded_buffer *bb = (bounded_buffer*) arg;
    int i, item;

    for (i = 0; i < BUFFER_SIZE*2; i++) {
        sem_wait(bb->full);
        sem_wait(bb->mutex);

        item = bb->buffer[bb->out];
        bb->out = (bb->out + 1) % BUFFER_SIZE;

        sem_post(bb->mutex);
        sem_post(bb->empty);

        printf("Consumed item %d\n", item);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    bounded_buffer *bb;
    int fd;

    // Create the shared memory object
    fd = shm_open("/shared_memory", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("shm_open");
        return 1;
    }

    // Set shared memory object size
    if (ftruncate(fd, sizeof(bounded_buffer)) == -1) {
        perror("ftruncate");
        return 1;
    }

    // Map the shared memory object into this process's address space
    bb = mmap(NULL, sizeof(bounded_buffer), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (bb == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Initialize the bounded buffer
    sem_unlink("/mutex");
    sem_unlink("/empty");
    sem_unlink("/full");

    bb->mutex = sem_open("/mutex", O_CREAT, S_IRUSR | S_IWUSR, 1);
    if (bb->mutex == SEM_FAILED) {
        perror("sem_open/mutex");
        return 1;
    }

    bb->empty = sem_open("/empty", O_CREAT, S_IRUSR | S_IWUSR, BUFFER_SIZE);
    if (bb->empty == SEM_FAILED) {
        perror("sem_open/empty");
        return 1;
    }

    bb->full = sem_open("/full", O_CREAT, S_IRUSR | S_IWUSR, 0);
    if (bb->full == SEM_FAILED) {
        perror("sem_open/full");
        return 1;
    }

    bb->in = 0;
    bb->out = 0;

    // Create producer and consumer threads
    pthread_t threads[NUMBER_OF_THREADS];
    int i;

    for (i = 0; i < NUMBER_OF_THREADS; i++) {
        if (i % 2 == 0) {
            pthread_create(&threads[i], NULL, producer, (void*) bb);
        } else {
            pthread_create(&threads[i], NULL, consumer, (void*) bb);
        }
    }

    // Wait for the threads to finish
    for (i = 0; i < NUMBER_OF_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    sem_close(bb->mutex);
    sem_close(bb->empty);
    sem_close(bb->full);

    munmap(bb, sizeof(bounded_buffer));
    shm_unlink("/shared_memory");

    return 0;
}