//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <sys/time.h>

#define MAX_THREADS 5
#define MAX_PACKETS 100

// struct for packets
typedef struct packet_struct {
    int id;
    int size;
} packet;

// struct for threads and their packet queues
typedef struct thread_struct {
    int number;
    int count;
    packet *queue[MAX_PACKETS];
    pthread_mutex_t queue_mutex;
    pthread_t thread;
    double total_size;
    double total_time;
} thread;

// array of threads
thread threads[MAX_THREADS];

void *process_packets(void *arg) {
    thread *t = (thread *)arg;
    int i;
    while (1) {
        // get next packet from queue
        packet *p = NULL;
        pthread_mutex_lock(&t->queue_mutex);
        for (i = 0; i < t->count; i++) {
            if (t->queue[i] != NULL) {
                p = t->queue[i];
                t->queue[i] = NULL;
                break;
            }
        }
        pthread_mutex_unlock(&t->queue_mutex);
        if (p == NULL) {
            break;
        }
        // delay based on packet size
        usleep(p->size * 1000);
        double time_diff;
        struct timeval tv;
        gettimeofday(&tv, NULL);
        time_diff = (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0 - t->total_time;
        // update total size and time for this thread
        pthread_mutex_lock(&t->queue_mutex);
        t->total_size += p->size;
        t->total_time += time_diff;
        pthread_mutex_unlock(&t->queue_mutex);
        free(p);
    }
    pthread_exit(NULL);
}

void print_stats() {
    double total_time = 0.0;
    double total_size = 0.0;
    int i;
    printf("\n***** Thread Statistics *****\n");
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_mutex_lock(&threads[i].queue_mutex);
        printf("Thread %d processed %d packets, with a total size of %.2f KB in %.2f seconds.\n", 
            threads[i].number, MAX_PACKETS - threads[i].count, threads[i].total_size / 1024.0, threads[i].total_time);
        total_size += threads[i].total_size;
        total_time = (threads[i].total_time > total_time) ? threads[i].total_time : total_time;
        pthread_mutex_unlock(&threads[i].queue_mutex);
    }
    printf("Total network throughput: %.2f KB/s\n", total_size / total_time / 1024.0);
}

void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("\nReceived SIGINT. Stats:\n");
        print_stats();
        exit(0);
    }
}

int main(int argc, char **argv) {
    int i, j;
    int packet_sizes[] = {1, 2, 4, 8, 16, 32, 64, 128, 256};
    signal(SIGINT, sig_handler);
    // initialize threads and packet queues
    for (i = 0; i < MAX_THREADS; i++) {
        threads[i].number = i;
        threads[i].count = 0;
        threads[i].total_size = 0.0;
        threads[i].total_time = 0.0;
        pthread_mutex_init(&threads[i].queue_mutex, NULL);
        pthread_create(&threads[i].thread, NULL, process_packets, &threads[i]);
    }
    // send packets to random threads
    srand(time(NULL));
    for (i = 0; i < MAX_PACKETS; i++) {
        int thread_number = rand() % MAX_THREADS;
        packet *p = (packet *)malloc(sizeof(packet));
        p->id = i;
        p->size = packet_sizes[rand() % 9];
        pthread_mutex_lock(&threads[thread_number].queue_mutex);
        for (j = 0; j < MAX_PACKETS; j++) {
            if (threads[thread_number].queue[j] == NULL) {
                threads[thread_number].queue[j] = p;
                threads[thread_number].count++;
                break;
            }
        }
        pthread_mutex_unlock(&threads[thread_number].queue_mutex);
    }
    // wait for threads to finish
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i].thread, NULL);
    }
    print_stats();
    return 0;
}