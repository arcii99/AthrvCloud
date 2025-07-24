//FormAI DATASET v1.0 Category: File Backup System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate random number between min (inclusive) and max (inclusive)
int randomize(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL)); // Initialize random seed based on current time
    
    // Generate 50 backup files with random sizes between 1KB and 1000KB
    int file_sizes[50];
    for (int i = 0; i < 50; i++) {
        file_sizes[i] = randomize(1, 1000);
    }
    
    // Calculate the total size of the backup files
    int total_size = 0;
    for (int i = 0; i < 50; i++) {
        total_size += file_sizes[i];
    }
    
    // Check if there is enough free space on the backup device (10GB minimum)
    int free_space = 10000000000; // 10GB in bytes
    if (total_size > free_space) {
        printf("Not enough free space on the backup device.\n");
        return 1;
    }
    
    // Backup the files one by one
    for (int i = 0; i < 50; i++) {
        // Generate a random file name
        char file_name[10];
        for (int j = 0; j < 9; j++) { // 9 characters plus the null terminator
            file_name[j] = randomize(65, 90); // ASCII capital letters
        }
        file_name[9] = '\0'; // Add the null terminator
        
        // Generate a random backup start time
        int start_time = randomize(time(NULL) - 604800, time(NULL)); // Within the last week
        
        // Print the backup information to the console
        printf("Backing up file %s (%dKB)...\n", file_name, file_sizes[i]);
        printf("Start time: %d\n", start_time);
        printf("----------------------------------------\n");
    }
    
    return 0;
}