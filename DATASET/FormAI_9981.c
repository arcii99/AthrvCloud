//FormAI DATASET v1.0 Category: File handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void recursive_count(FILE *file, int *count) {
    char c = fgetc(file);
    if (c == EOF) {     // base case: end of file
        return;
    }
    if (c == '\n') {    // increment count if newline character is found
        (*count)++;
    }
    recursive_count(file, count);   // recursive call
}

int main() {
    FILE *file;
    char filename[100];
    int count = 0;
    
    // get file name from user
    printf("Enter file name: ");
    scanf("%s", filename);
    
    // open the file in read mode
    file = fopen(filename, "r");
    
    // check if file exists
    if (file == NULL) {
        printf("File not found.\n");
        exit(1);    // exit program with error code 1
    }
    
    // call recursive function to count lines in file
    recursive_count(file, &count);
    
    // close file
    fclose(file);
    
    printf("Number of lines: %d\n", count);
    
    return 0;   // exit program with success code 0
}