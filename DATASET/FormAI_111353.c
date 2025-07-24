//FormAI DATASET v1.0 Category: System boot optimizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Number of files being optimized
#define FILES_TO_OPTIMIZE 10

// Optimize file function 
void optimizeFile(char* fileName) {
    printf("Optimizing %s\n", fileName);
    // Simulate file optimization by waiting for random time
    int timeToWait = rand() % 5 + 1;
    sleep(timeToWait);
    printf("%s optimization completed in %d seconds\n", fileName, timeToWait);
}

// Main function starts here
int main() {
   
    // Array of file names to be optimized
    char* files[FILES_TO_OPTIMIZE] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt", "file6.txt", "file7.txt", "file8.txt", "file9.txt", "file10.txt"};
    int i;

    printf("Starting System Boot Optimizer...\n");

    // Loop through each file and optimize
    for (i = 0; i < FILES_TO_OPTIMIZE; i++) {
        optimizeFile(files[i]);
    }

    printf("System boot optimization complete!\n");

    return 0;
}