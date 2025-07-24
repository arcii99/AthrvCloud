//FormAI DATASET v1.0 Category: Email Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SIZE 1024

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

typedef struct {
    char* sender;
    char* receiver;
    char* subject;
    char* body;
} email_t;

typedef struct {
    email_t* emails[MAX_SIZE];
    int size;
    int capacity;
} inbox_t;

inbox_t inbox;

void init_inbox() {
    inbox.size = 0;
    inbox.capacity = MAX_SIZE;
    for (int i = 0; i < MAX_SIZE; i++) {
        inbox.emails[i] = NULL;
    }
}

void print_email(email_t* email) {
    printf("From: %s\n", email->sender);
    printf("To: %s\n", email->receiver);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n\n", email->body);
}

void send_email(email_t* email) {
    pthread_mutex_lock(&mutex);
    while (inbox.size >= inbox.capacity) {
        pthread_cond_wait(&cond, &mutex);
    }
    inbox.emails[inbox.size++] = email;
    printf("\nNew email received!\n");
    print_email(email);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
}

void* receive_email(void* arg) {
    email_t* email = (email_t*) arg;
    send_email(email);
    free(email->sender);
    free(email->receiver);
    free(email->subject);
    free(email->body);
    free(email);
    return NULL;
}

void* read_email(void* arg) {
    char sender[MAX_SIZE];
    char receiver[MAX_SIZE];
    char subject[MAX_SIZE];
    char body[MAX_SIZE];
    printf("Enter sender email address:\n");
    scanf("%s", sender);
    printf("Enter receiver email address:\n");
    scanf("%s", receiver);
    printf("Enter email subject:\n");
    scanf("%s", subject);
    printf("Enter email body:\n");
    scanf("%s", body);
    email_t* email = malloc(sizeof(email_t));
    email->sender = strdup(sender);
    email->receiver = strdup(receiver);
    email->subject = strdup(subject);
    email->body = strdup(body);
    receive_email(email);
    return NULL;
}

void* view_inbox(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (inbox.size == 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        for (int i = 0; i < inbox.size; i++) {
            email_t* email = inbox.emails[i];
            print_email(email);
            free(email->sender);
            free(email->receiver);
            free(email->subject);
            free(email->body);
            free(email);
            inbox.emails[i] = NULL;
        }
        inbox.size = 0;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    init_inbox();
    pthread_t thread1, thread2, thread3;
    pthread_create(&thread1, NULL, read_email, NULL);
    pthread_create(&thread2, NULL, read_email, NULL);
    pthread_create(&thread3, NULL, view_inbox, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    return 0;
}