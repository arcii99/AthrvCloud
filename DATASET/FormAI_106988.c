//FormAI DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>

int main() {

    // Creating a file pointer to the file
    FILE *fp;
    
    // Opening the file in write mode
    fp = fopen("output.txt", "w");
    
    // Writing some data to the file
    fprintf(fp, "Hello, world!\n");
    fprintf(fp, "This is a sample text written to a file using C file handling.\n");
    fprintf(fp, "Let's write some more lines to this file!\n");
    
    // Closing the file
    fclose(fp);
    
    // Re-opening the file in read mode
    fp = fopen("output.txt", "r");
    
    // Reading the data from the file and printing it to the console
    char c = fgetc(fp);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fp);
    }
    
    // Closing the file
    fclose(fp);
    
    printf("\nDone reading from file!");

    return 0;
}