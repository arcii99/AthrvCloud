//FormAI DATASET v1.0 Category: File Backup System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int generateRandomNum(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to create backup
void createBackup() {
    time_t t = time(NULL); // Get current time
    struct tm tm = *localtime(&t);
    char filename[40]; // Name of backup file
    sprintf(filename, "backup_%04d-%02d-%02d_%02d-%02d-%02d.txt", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    FILE *fptr;
    fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Error creating backup!\n");
    } else {
        printf("Backup created successfully: %s\n", filename);
    }
    fclose(fptr);
}

// Main function
int main() {
    int i;
    srand(time(NULL)); // Seed random number generator
    for (i = 0; i < 10; i++) {
        if (generateRandomNum(1, 100) <= 25) {
            createBackup();
        } else {
            printf("No backup created\n");
        }
    }
    return 0;
}