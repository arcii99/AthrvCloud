//FormAI DATASET v1.0 Category: QR code reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>
#include <time.h>

#define QR_CODE_LENGTH 14 // Length of QR code to be scanned

sem_t sem; // Semaphore for locking critical section
char qr_code[QR_CODE_LENGTH]; // Variable to hold QR code after scanning

void* scanner(void* arg) {
    int random_number;
    char* characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; // Set of characters to generate random QR code
    srand(time(NULL)); // Initialize random seed
    
    while(1) {
        // Generate random QR code
        for(int i = 0; i < QR_CODE_LENGTH; i++) {
            random_number = rand() % 62;
            qr_code[i] = characters[random_number];
        }
        
        sem_wait(&sem); // Enter critical section
        printf("Scanned QR code: %s\n", qr_code);
        sem_post(&sem); // Exit critical section
        
        sleep(1);
    }
}

void* reader(void* arg) {
    char* qr_code_buffer = (char*) arg;
    
    while(1) {
        sem_wait(&sem); // Enter critical section
        
        // Check if QR code has been scanned
        if(strcmp(qr_code, qr_code_buffer) != 0) {
            strcpy(qr_code_buffer, qr_code);
            printf("Read QR code: %s\n", qr_code_buffer);
        }
        
        sem_post(&sem); // Exit critical section
        usleep(100000);
    }
}

int main() {
    pthread_t scanner_thread, reader_thread;
    char qr_code_buffer[QR_CODE_LENGTH] = {0};
    
    sem_init(&sem, 0, 1); // Initialize semaphore
    
    // Create scanner thread
    if(pthread_create(&scanner_thread, NULL, scanner, NULL) != 0) {
        printf("Error: Failed to create scanner thread.\n");
        exit(1);
    }
    
    // Create reader thread
    if(pthread_create(&reader_thread, NULL, reader, qr_code_buffer) != 0) {
        printf("Error: Failed to create reader thread.\n");
        exit(1);
    }
    
    // Wait for threads to finish
    pthread_join(scanner_thread, NULL);
    pthread_join(reader_thread, NULL);
    
    sem_destroy(&sem); // Destroy semaphore
    
    return 0;
}