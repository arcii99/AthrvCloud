//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Define maximum file path size
#define MAX_PATH_SIZE 100

// Define file structure
typedef struct {
    char path[MAX_PATH_SIZE];
    bool isSynced;
} File;

// Declare global variables
File files[5] = {
    {"assets/file1.txt", false},
    {"assets/file2.txt", false},
    {"assets/file3.txt", false},
    {"assets/file4.txt", false},
    {"assets/file5.txt", false},
};
int totalFiles = sizeof(files)/sizeof(files[0]);

// Define sync function
void syncFiles() {
    srand(time(NULL));
    int randomIndex = rand() % totalFiles;
    strcpy(files[randomIndex].path, "assets/random.txt");
    files[randomIndex].isSynced = true;
    printf("\nOh, an error occurred in my code,\nBut fear not, for I will fix the mode!\n");
    printf("I'll synchronize the files in a snap,\nNo more errors, no more mishaps!\n");
}

// Define main function
int main() {
    printf("Oh, my dear friend, could thou help me out?\nI have files that need to be without doubt,\nSynchronized on this lovely day,\nAnd all the errors to be swept away!\n\n");
    printf("Press any key to continue.\n\n");
    getchar();

    syncFiles();

    printf("\nThe files have now been synchronized,\nBut it was not done un-disguised!\nFor I have shuffled the paths around,\nSo the synced files can't be found!\n");

    int syncedCount = 0;
    for (int i = 0; i < totalFiles; i++) {
        if (files[i].isSynced) {
            syncedCount++;
        }
    }
    printf("\nWe have synchronized %d files in total,\nWe did not end up in a code fatal!\n", syncedCount);

    return 0;
}