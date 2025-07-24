//FormAI DATASET v1.0 Category: Email Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define MAX_THREADS 10

void send_email(char* recipient, char* subject, char* content) {
    // Implementation of email sending functionality
    printf("To: %s\nSubject: %s\nContent: %s\n\n", recipient, subject, content);
}

void* email_handler(void* arg) {
    char* email = (char*) arg;
    char* recipient;
    char* subject;
    char* content;
    char* token;
    const char delimiters[] = "|";

    token = strtok(email, delimiters);
    recipient = token;

    token = strtok(NULL, delimiters);
    subject = token;

    token = strtok(NULL, delimiters);
    content = token;

    send_email(recipient, subject, content);

    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Error: Please provide a filename as input\n");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    FILE* fp = fopen(argv[1], "r");
    pthread_t threads[MAX_THREADS];
    int num_threads = 0;
    int i;

    if(fp == NULL) {
        printf("Error: Unable to open file %s\n", argv[1]);
        return -1;
    }

    while(fgets(buffer, BUFFER_SIZE, fp)) {
        pthread_create(&threads[num_threads], NULL, email_handler, (void*) strdup(buffer));
        num_threads++;

        if(num_threads >= MAX_THREADS) {
            // Wait for threads to finish if maximum number of threads have been spawned
            for(i = 0; i < MAX_THREADS; i++) {
                pthread_join(threads[i], NULL);
            }

            num_threads = 0;
        }
    }

    // Wait for remaining threads to finish
    for(i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(fp);
    
    return 0;
}