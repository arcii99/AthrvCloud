//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LENGTH 100
#define MAX_EMAILS 100

// Struct for email data
typedef struct {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
} Email;

// Global variables
Email mailingList[MAX_EMAILS];
int numEmails = 0;
pthread_mutex_t mutex;

// Function prototypes
void* addEmail();
void* removeEmail();

int main() {

    pthread_t thread1, thread2;

    // Initialize mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Mutex initialization failed.\n");
        return 1;
    }

    // Create threads
    pthread_create(&thread1, NULL, addEmail, NULL);
    pthread_create(&thread2, NULL, removeEmail, NULL);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print final mailing list
    printf("\nFinal Mailing List:\n");
    for (int i = 0; i < numEmails; i++) {
        printf("%s <%s>\n", mailingList[i].name, mailingList[i].email);
    }

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}

void* addEmail() {
    while (1) {
        // Get input
        char name[MAX_LENGTH];
        char email[MAX_LENGTH];
        printf("Enter name: ");
        fgets(name, MAX_LENGTH, stdin);
        printf("Enter email: ");
        fgets(email, MAX_LENGTH, stdin);

        // Remove new line character from input
        name[strcspn(name, "\n")] = 0;
        email[strcspn(email, "\n")] = 0;

        // Lock mutex
        pthread_mutex_lock(&mutex);

        // Add new email to mailing list
        strcpy(mailingList[numEmails].name, name);
        strcpy(mailingList[numEmails].email, email);
        numEmails++;

        // Unlock mutex
        pthread_mutex_unlock(&mutex);
    }
}

void* removeEmail() {
    while (1) {
        // Get input
        char emailToRemove[MAX_LENGTH];
        printf("Enter email to remove: ");
        fgets(emailToRemove, MAX_LENGTH, stdin);

        // Remove new line character from input
        emailToRemove[strcspn(emailToRemove, "\n")] = 0;

        // Lock mutex
        pthread_mutex_lock(&mutex);

        // Search for email in mailing list
        int emailIndex = -1;
        for (int i = 0; i < numEmails; i++) {
            if (strcmp(mailingList[i].email, emailToRemove) == 0) {
                emailIndex = i;
                break;
            }
        }

        // Remove email from mailing list
        if (emailIndex != -1) {
            for (int i = emailIndex; i < numEmails-1; i++) {
                strcpy(mailingList[i].name, mailingList[i+1].name);
                strcpy(mailingList[i].email, mailingList[i+1].email);
            }
            numEmails--;
            printf("Email removed.\n");
        } else {
            printf("Email not found.\n");
        }

        // Unlock mutex
        pthread_mutex_unlock(&mutex);
    }
}