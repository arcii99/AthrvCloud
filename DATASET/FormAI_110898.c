//FormAI DATASET v1.0 Category: System boot optimizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void optimize(char *file) {
    // Exit condition
    if (strlen(file) == 0) {
        return;
    }
    
    // Recursive call to optimize next file
    optimize(&file[1]);
    
    // Print current file name
    printf("Optimizing file: %s\n", file);
    
    // Simulating optimization process
    printf("File optimized.\n");
}

int main() {
    // Array of files to optimize
    char files[5][10] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};
    
    // Optimize files recursively
    for (int i = 0; i < 5; i++) {
        optimize(files[i]);
    }
    
    // Exit program
    return 0;
}