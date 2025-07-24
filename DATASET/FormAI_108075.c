//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to calculate disk space usage
void calculate_disk_usage(char* path) {
    printf("\nAnalyzing disk space usage in %s...\n", path);
    int total_space = 500;
    int used_space = rand() % total_space;
    int free_space = total_space - used_space;

    printf("\nTotal disk space: %d GB", total_space);
    printf("\nUsed disk space: %d GB", used_space);
    printf("\nFree disk space: %d GB\n", free_space);

    if(used_space > total_space / 2) {
        printf("\nWhoa! Looks like you're running out of disk space. Better clean up your files ASAP!\n");
    }
    else {
        printf("\nPlenty of space left! Keep on saving those files.\n");
    }
}

// Function to check if directory exists
bool directory_exists(const char* path) {
    printf("\nChecking if directory %s exists...", path);
    bool directory_exists = rand() % 2;
    
    if(directory_exists) {
        printf("\nDirectory exists!\n");
    }
    else {
        printf("\nDirectory not found.\n");
    }

    return directory_exists;
}

// Main function
int main() {
    char* path = "/surreal/c:/users/imaginary/folder";
    if(directory_exists(path)) {
        calculate_disk_usage(path);
    }

    return 0;
}