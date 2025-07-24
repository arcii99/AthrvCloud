//FormAI DATASET v1.0 Category: Email Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5
#define MAX_MAILBOX_SIZE 10

typedef struct {
    char* sender;
    char* subject;
    char* message;
} Email;

typedef struct {
    Email* mailbox[MAX_MAILBOX_SIZE];
    int start;
    int end;
    int num_emails;
    pthread_mutex_t mutex;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;
} Mailbox;

void* receive_emails(void* arg) {
    Mailbox* mailbox = (Mailbox*) arg;
    while (1) {
        pthread_mutex_lock(&mailbox->mutex);
        while (mailbox->num_emails == 0) {
            pthread_cond_wait(&mailbox->not_empty, &mailbox->mutex);
        }
        Email* email = mailbox->mailbox[mailbox->start];
        printf("To: %s\nSubject: %s\nMessage: %s\n", email->sender, email->subject, email->message);
        mailbox->start = (mailbox->start + 1) % MAX_MAILBOX_SIZE;
        mailbox->num_emails--;
        pthread_cond_signal(&mailbox->not_full);
        pthread_mutex_unlock(&mailbox->mutex);
    }
}

void* send_email(void* arg) {
    Mailbox* mailbox = (Mailbox*) arg;
    Email* email = (Email*) malloc(sizeof(Email));
    email->sender = "example@aol.com";
    email->subject = "Hello World!";
    email->message = "This is a test email.";
    while (1) {
        pthread_mutex_lock(&mailbox->mutex);
        while (mailbox->num_emails == MAX_MAILBOX_SIZE) {
            pthread_cond_wait(&mailbox->not_full, &mailbox->mutex);
        }
        mailbox->mailbox[mailbox->end] = email;
        printf("Sending email to: %s\n", email->sender);
        mailbox->end = (mailbox->end + 1) % MAX_MAILBOX_SIZE;
        mailbox->num_emails++;
        pthread_cond_signal(&mailbox->not_empty);
        pthread_mutex_unlock(&mailbox->mutex);
    }
}

int main() {
    Mailbox mailbox;
    mailbox.start = 0;
    mailbox.end = 0;
    mailbox.num_emails = 0;
    pthread_mutex_init(&mailbox.mutex, NULL);
    pthread_cond_init(&mailbox.not_full, NULL);
    pthread_cond_init(&mailbox.not_empty, NULL);

    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS - 1; i++) {
        pthread_create(&threads[i], NULL, receive_emails, &mailbox);
    }

    pthread_create(&threads[MAX_THREADS - 1], NULL, send_email, &mailbox);

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mailbox.mutex);
    pthread_cond_destroy(&mailbox.not_full);
    pthread_cond_destroy(&mailbox.not_empty);

    return 0;
}