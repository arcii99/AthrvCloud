//FormAI DATASET v1.0 Category: Syntax parsing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 100

typedef struct Token {
    char value[MAX_BUFFER_SIZE];
    char type[MAX_BUFFER_SIZE];
} Token;

Token buffer[MAX_BUFFER_SIZE];
int buffer_count = 0;
bool done = false;

pthread_mutex_t buffer_mutex;
pthread_cond_t buffer_not_empty;
pthread_cond_t buffer_not_full;

void parse(char *input) {
    // Parse input and add tokens to buffer
    Token new_token;
    strcpy(new_token.value, input);
    strcpy(new_token.type, "SYNTAX");
    
    pthread_mutex_lock(&buffer_mutex);
    while (buffer_count == MAX_BUFFER_SIZE) {
        pthread_cond_wait(&buffer_not_full, &buffer_mutex);
    }
    buffer[buffer_count] = new_token;
    buffer_count++;
    pthread_mutex_unlock(&buffer_mutex);
    pthread_cond_signal(&buffer_not_empty);
}

void *consume(void *arg) {
    Token consumed_token;
    while (!done) {
        pthread_mutex_lock(&buffer_mutex);
        while (buffer_count == 0 && !done) {
            pthread_cond_wait(&buffer_not_empty, &buffer_mutex);
        }
        if (done) {
            pthread_mutex_unlock(&buffer_mutex);
            break;
        }
        consumed_token = buffer[buffer_count-1];
        buffer_count--;
        pthread_mutex_unlock(&buffer_mutex);
        pthread_cond_signal(&buffer_not_full);
        
        // Do something with consumed_token
        printf("Consumed token - Value: %s Type: %s\n", consumed_token.value, consumed_token.type);
    }
    printf("Consumer terminating\n");
    return NULL;
}

int main() {
    pthread_t consumer_thread;
    
    if (pthread_mutex_init(&buffer_mutex, NULL) != 0) {
        perror("Error initializing mutex");
        return EXIT_FAILURE;
    }
    if (pthread_cond_init(&buffer_not_empty, NULL) != 0) {
        perror("Error initializing condition variable buffer_not_empty");
        return EXIT_FAILURE;
    }
    if (pthread_cond_init(&buffer_not_full, NULL) != 0) {
        perror("Error initializing condition variable buffer_not_full");
        return EXIT_FAILURE;
    }
    
    if (pthread_create(&consumer_thread, NULL, consume, NULL) != 0) {
        perror("Error creating consumer thread");
        return EXIT_FAILURE;
    }
    
    // Parse some inputs
    parse("int x = 5;");
    parse("printf(\"Hello World!\");");
    parse("for (i=0; i<10; i++) {");
    
    done = true;
    pthread_cond_broadcast(&buffer_not_empty);
    pthread_join(consumer_thread, NULL);
    
    pthread_mutex_destroy(&buffer_mutex);
    pthread_cond_destroy(&buffer_not_empty);
    pthread_cond_destroy(&buffer_not_full);
    
    return EXIT_SUCCESS;
}