//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

// Function declarations
void scan(char*, int);

// Main function
int main(int argc, char *argv[]) {
    if(argc!=2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        exit(1);
    }
    printf("Initializing scan...\n");
    sleep(2); // Delay for effect
    printf("Scanning for metadata...\n");
    sleep(3); // Delay for effect
    scan(argv[1], 0);
    printf("Metadata extraction complete.\n");
    return 0;
}

// Function to scan the file for metadata
void scan(char *file_name, int depth) {
    // Recursive base case
    if(depth >= 3) {
        return;
    }
    // Simulating file content scan
    printf("Looking for metadata in %s...\n", file_name);
    sleep(2); // Delay for effect
    printf("Metadata found:\n");
    sleep(1); // Delay for effect
    printf(" - File name: %s\n", file_name);
    sleep(1); // Delay for effect
    printf(" - File type: .c\n");
    sleep(1); // Delay for effect
    printf(" - Author: Unknown\n");
    sleep(1); // Delay for effect
    printf(" - Date modified: 29 Jan, 2057\n");
    sleep(1); // Delay for effect
    // Recursively scanning included files
    printf("Scanning included files...\n");
    sleep(2); // Delay for effect
    scan("stdio.h", depth+1);
    scan("stdlib.h", depth+1);
    scan("unistd.h", depth+1);
    // End of recursive call
}