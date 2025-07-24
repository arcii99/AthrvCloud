//FormAI DATASET v1.0 Category: Email Client ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 500

typedef struct email_t {
    char sender[50];
    char receiver[50];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
} email;

void* send_email(void* arg) {
    email* e = (email*) arg;
    printf("Sending email from: %s to: %s\nSubject: %s\nBody: %s\n\n", e->sender, e->receiver, e->subject, e->body);
    // Code to send email
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5]; // Number of threads to create
    int rc, i;
    email emails[5] = {
        {"user1@mail.com", "user2@mail.com", "Test Email 1", "This is a test email."},
        {"user1@mail.com", "user3@mail.com", "Test Email 2", "This is another test email."},
        {"user4@mail.com", "user2@mail.com", "Test Email 3", "Yet another test email."},
        {"user5@mail.com", "user3@mail.com", "Test Email 4", "This is a test email with longer content."},
        {"user6@mail.com", "user2@mail.com", "Test Email 5", "This is a test email with even longer content!"},
    };
    for (i = 0; i < 5; i++) {
        rc = pthread_create(&threads[i], NULL, send_email, (void*) &emails[i]);
        if (rc) {
            printf("Error in thread creation!");
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}