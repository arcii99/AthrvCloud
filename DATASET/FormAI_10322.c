//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define BUFFER_SIZE 50
#define THRESHOLD 10

int buffer[BUFFER_SIZE]; // buffer to hold network packets
int buffer_count = 0; // number of packets in the buffer
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // mutex for synchronization

void add_packet(int packet) {
    pthread_mutex_lock(&mutex);
    if (buffer_count < BUFFER_SIZE) {
        buffer[buffer_count++] = packet;
    }
    pthread_mutex_unlock(&mutex);
}

void* processor(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (buffer_count >= THRESHOLD) {
            printf("Intrusion detected!\n");
            // take necessary actions
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, processor, NULL);
    
    // simulate network traffic
    for (int i = 0; i < 100; i++) {
        add_packet(i);
    }
    
    pthread_join(thread, NULL);
    return 0;
}