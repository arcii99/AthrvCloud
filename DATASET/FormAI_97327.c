//FormAI DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>

int main() {
    // Creating a file pointer and a filename string
    FILE *fp;
    char filename[] = "example.txt";
    
    // Opening the file for writing
    fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 0;
    }
    
    // Writing to the file using fprintf
    fprintf(fp, "Hello world!\n");
    fprintf(fp, "This is a unique C file handling example program.\n");
    fprintf(fp, "It was written in an ephemeral style, just like a fleeting thought.\n");
    fprintf(fp, "But unlike a thought, it shall be preserved on this computer for eternity.\n");
    fprintf(fp, "Or until someone deletes it.\n");
    
    // Closing the file
    fclose(fp);
    
    // Opening the file for reading
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 0;
    }
    
    // Reading from the file using fgets
    char buffer[100];
    while(fgets(buffer, 100, fp) != NULL) {
        printf("%s", buffer);
    }
    
    // Closing the file
    fclose(fp);
    
    return 0;
}