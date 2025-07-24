//FormAI DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#define MAX_PASSWORDS 100
#define MAX_LENGTH 50

// Structure for password object
typedef struct {
    char password[MAX_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int passwordCount = 0;

// Mutex for accessing passwordCount
pthread_mutex_t passwordCountMutex = PTHREAD_MUTEX_INITIALIZER;

// Mutex for accessing passwords array
pthread_mutex_t passwordMutex = PTHREAD_MUTEX_INITIALIZER;

// Function to add password to password array
void addPassword(char* password, int length) {
    // Lock mutex when accessing shared resource
    pthread_mutex_lock(&passwordMutex);

    // Copy password to Password object
    Password newPass;
    strcpy(newPass.password, password);
    newPass.length = length;

    // Add password to password array
    passwords[passwordCount++] = newPass;

    // Unlock mutex when finished accessing shared resource
    pthread_mutex_unlock(&passwordMutex);
}

// Thread function to get password from user input
void* getPasswordInput(void* arg) {
    char password[MAX_LENGTH];
    printf("Enter a password to add to the password manager: ");
    scanf("%s", password);
    int length = strlen(password);

    // Lock mutex when accessing shared resource
    pthread_mutex_lock(&passwordCountMutex);

    // Check if password array is already full
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Password manager is full. Cannot add password.\n");
        // Unlock mutex before returning
        pthread_mutex_unlock(&passwordCountMutex);
        return NULL;
    }

    // Add password to password array
    addPassword(password, length);

    // Unlock mutex before returning
    pthread_mutex_unlock(&passwordCountMutex);

    return NULL;
}

// Thread function to print all passwords in password manager
void* printPasswords(void* arg) {
    // Lock mutex when accessing shared resource
    pthread_mutex_lock(&passwordMutex);

    printf("Passwords in the password manager:\n");
    for (int i = 0; i < passwordCount; i++) {
        Password p = passwords[i];
        printf("%s\n", p.password);
    }

    // Unlock mutex before returning
    pthread_mutex_unlock(&passwordMutex);

    return NULL;
}

int main() {
    // Create input thread
    pthread_t inputThread;
    pthread_create(&inputThread, NULL, getPasswordInput, NULL);

    // Create print thread
    pthread_t printThread;
    pthread_create(&printThread, NULL, printPasswords, NULL);

    // Wait for input thread to finish
    pthread_join(inputThread, NULL);

    // Wait for print thread to finish
    pthread_join(printThread, NULL);

    // Destroy mutexes
    pthread_mutex_destroy(&passwordMutex);
    pthread_mutex_destroy(&passwordCountMutex);
    
    return 0;
}