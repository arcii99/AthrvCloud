//FormAI DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_THREADS 4
#define MAX_PASSWORDS 100

// Global variables to hold password data
char passwords[MAX_PASSWORDS][20];
int password_count = 0;

// Function to check if two passwords match
int passwords_match(char* password1, char* password2) {
    return strcmp(password1, password2) == 0;
}

// Function to add a password to the list
void add_password(char* password) {
    // Check if the password is already in the list
    int i;
    for (i = 0; i < password_count; i++) {
        if (passwords_match(password, passwords[i])) {
            printf("Password already exists in the list\n");
            return;
        }
    }

    // Add the password to the list
    if (password_count == MAX_PASSWORDS) {
        printf("Maximum number of passwords reached\n");
        return;
    }
    strcpy(passwords[password_count], password);
    password_count++;
    printf("Password added to list\n");
}

// Function to remove a password from the list
void remove_password(char* password) {
    // Search for the password
    int i;
    for (i = 0; i < password_count; i++) {
        if (passwords_match(password, passwords[i])) {
            // Remove the password
            int j;
            for (j = i; j < password_count - 1; j++) {
                strcpy(passwords[j], passwords[j+1]);
            }
            password_count--;
            printf("Password removed from list\n");
            return;
        }
    }
    printf("Password not found in the list\n");
}

// Function to print the list of passwords
void print_passwords() {
    printf("List of passwords:\n");
    int i;
    for (i = 0; i < password_count; i++) {
        printf("%s\n", passwords[i]);
    }
}

// Thread function to add a password to the list
void* add_password_thread(void* arg) {
    char* password = (char*) arg;
    add_password(password);
    pthread_exit(NULL);
}

// Thread function to remove a password from the list
void* remove_password_thread(void* arg) {
    char* password = (char*) arg;
    remove_password(password);
    pthread_exit(NULL);
}

int main() {
    // Initialize the password list
    memset(passwords, 0, MAX_PASSWORDS * 20);

    // Create an array of threads to manage passwords
    pthread_t threads[NUM_THREADS];

    // Add two passwords to the list
    char password1[] = "password1";
    pthread_create(&threads[0], NULL, add_password_thread, (void*) password1);
    char password2[] = "password2";
    pthread_create(&threads[1], NULL, add_password_thread, (void*) password2);

    // Wait for the threads to finish
    int i;
    for (i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the list of passwords
    print_passwords();

    // Remove a password from the list
    char password3[] = "password3";
    add_password(password3);
    char password4[] = "password4";
    add_password(password4);
    char password5[] = "password5";
    pthread_create(&threads[2], NULL, remove_password_thread, (void*) password5);
    pthread_join(threads[2], NULL);

    // Print the list of passwords
    print_passwords();

    return 0;
}