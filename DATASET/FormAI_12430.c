//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure for storing the intrusion information
typedef struct Intrusion {
    char ip_address[16];
    char username[20];
    char password[20];
} Intrusion;

// Function to perform intrusion detection
void *detect_intrusion(void *intrusion_ptr) {
    Intrusion *intrusion = (Intrusion *)intrusion_ptr;
    
    // Checks for suspicious activity in the login details
    if (strcmp(intrusion->username, "root") == 0 && strcmp(intrusion->password, "password") == 0) {
        printf("Intrusion detected from IP: %s\n", intrusion->ip_address);
    } else {
        printf("No intrusion detected from IP: %s\n", intrusion->ip_address);
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    int thread_status[3];
    Intrusion intrusions[3];
    
    // Initialize the intrusion information
    strcpy(intrusions[0].ip_address, "192.168.1.1");
    strcpy(intrusions[0].username, "admin");
    strcpy(intrusions[0].password, "password123");
    
    strcpy(intrusions[1].ip_address, "10.0.0.1");
    strcpy(intrusions[1].username, "root");
    strcpy(intrusions[1].password, "password");
    
    strcpy(intrusions[2].ip_address, "172.16.0.1");
    strcpy(intrusions[2].username, "user");
    strcpy(intrusions[2].password, "pass123");
    
    // Create threads for each intrusion
    for (int i = 0; i < 3; i++) {
        thread_status[i] = pthread_create(&threads[i], NULL, detect_intrusion, (void *)&intrusions[i]);
        if (thread_status[i] != 0) {
            printf("Error: Unable to create thread.\n");
            exit(1);
        }
    }
    
    // Wait for threads to finish executing
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}