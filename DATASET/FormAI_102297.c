//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <pthread.h>

#define MIN_LENGTH 8 // minimum length of the password
#define MAX_LENGTH 20 // maximum length of the password
#define NUM_THREADS 4 // number of threads to use

typedef struct {
    char *password;
    bool uppercase;
    bool lowercase;
    bool digit;
    bool special_char;
    int score;
} password_info;

void* check_length(void* arg);
void* check_uppercase(void* arg);
void* check_lowercase(void* arg);
void* check_digit(void* arg);
void* check_special_char(void* arg);

int main() {
    char password[MAX_LENGTH + 1]; // buffer for the password
    password_info info = { password, false, false, false, false, 0 }; // initialize info struct
    
    printf("Enter a password between %d and %d characters long: ", MIN_LENGTH, MAX_LENGTH);
    fgets(password, MAX_LENGTH + 1, stdin); // read password input
    password[strcspn(password, "\n")] = 0; // remove newline character
    
    // initialize threads
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int thread_result[NUM_THREADS];
    int i;
    
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    
    // check length
    thread_args[0] = 0;
    pthread_create(&threads[0], &attr, check_length, &info);
    
    // check for uppercase character
    thread_args[1] = 1;
    pthread_create(&threads[1], &attr, check_uppercase, &info);
    
    // check for lowercase character
    thread_args[2] = 2;
    pthread_create(&threads[2], &attr, check_lowercase, &info);
    
    // check for digit
    thread_args[3] = 3;
    pthread_create(&threads[3], &attr, check_digit, &info);
    
    // wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], (void**)&thread_result[i]);
    }
    
    // calculate password score based on criteria
    if (info.score >= 10) {
        printf("Password is strong!\n");
    } else if (info.score >= 6) {
        printf("Password is medium.\n");
    } else {
        printf("Password is weak.\n");
    }
    
    return 0;
}

// Check if password is between min and max length.
void* check_length(void* arg) {
    password_info* info = (password_info*)arg;
    int password_length = strlen(info->password);
    if (password_length < MIN_LENGTH) {
        printf("Password is too short. Must be at least %d characters long.\n", MIN_LENGTH);
    } else if (password_length > MAX_LENGTH) {
        printf("Password is too long. Must be at most %d characters long.\n", MAX_LENGTH);
    } else {
        info->score++;
    }
    pthread_exit(NULL);
}

// Check for at least one uppercase character.
void* check_uppercase(void* arg) {
    password_info* info = (password_info*)arg;
    char* password = info->password;
    while (*password) {
        if (isupper(*password)) {
            info->uppercase = true;
            info->score++;
            pthread_exit(NULL);
        }
        password++;
    }
    printf("Password must contain at least one uppercase character.\n");
    pthread_exit(NULL);
}

// Check for at least one lowercase character.
void* check_lowercase(void* arg) {
    password_info* info = (password_info*)arg;
    char* password = info->password;
    while (*password) {
        if (islower(*password)) {
            info->lowercase = true;
            info->score++;
            pthread_exit(NULL);
        }
        password++;
    }
    printf("Password must contain at least one lowercase character.\n");
    pthread_exit(NULL);
}

// Check for at least one digit.
void* check_digit(void* arg) {
    password_info* info = (password_info*)arg;
    char* password = info->password;
    while (*password) {
        if (isdigit(*password)) {
            info->digit = true;
            info->score++;
            pthread_exit(NULL);
        }
        password++;
    }
    printf("Password must contain at least one digit.\n");
    pthread_exit(NULL);
}

// Check for at least one special character.
void* check_special_char(void* arg) {
    password_info* info = (password_info*)arg;
    char* password = info->password;
    while (*password) {
        if (ispunct(*password)) {
            info->special_char = true;
            info->score++;
            pthread_exit(NULL);
        }
        password++;
    }
    printf("Password must contain at least one special character.\n");
    pthread_exit(NULL);
}