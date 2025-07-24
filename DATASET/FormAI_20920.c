//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define THREAD_COUNT 4
#define TEXT_SIZE 256
#define ENCRYPT_SHIFT 3

char text[TEXT_SIZE];
char encrypted_text[TEXT_SIZE];
pthread_mutex_t mutex;

void encrypt_text(char *text, int shift) {
    int length = strlen(text);
    int i;
    for(i = 0; i < length; i++) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        } else if(text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
    } 
}

void *encrypt_thread(void *id_ptr) {
    int thread_id = *(int*)id_ptr;
    int start = thread_id * (TEXT_SIZE / THREAD_COUNT);
    int end = (thread_id + 1) * (TEXT_SIZE / THREAD_COUNT);
    pthread_mutex_lock(&mutex);
    printf("Thread %d is encrypting characters from %d to %d\n", thread_id, start, end-1);
    encrypt_text(&text[start], ENCRYPT_SHIFT);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREAD_COUNT];
    int thread_ids[THREAD_COUNT];
    int i, rc;
    printf("Enter a text to encrypt: ");
    fgets(text, TEXT_SIZE, stdin);
    text[strcspn(text, "\r\n")] = 0;
    for(i = 0; i < THREAD_COUNT; i++) {
        thread_ids[i] = i;
        rc = pthread_create(&threads[i], NULL, encrypt_thread, &thread_ids[i]);
        if(rc) {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }
    for(i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Encrypted text: %s\n", text);
    return 0;
}