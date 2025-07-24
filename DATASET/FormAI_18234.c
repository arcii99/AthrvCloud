//FormAI DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>

int main() {
    // Creating a file pointer and opening file in write mode
    FILE *fp = fopen("example.txt", "w");

    // Writing to the file
    fprintf(fp, "This is an example program that demonstrates file handling in C.\n");
    fprintf(fp, "We can read and write data from and to files using file pointers in C.\n");
    fprintf(fp, "File handling is an essential aspect of programming and is used to store data persistently.\n");
    
    // Closing the file
    fclose(fp);

    // Re-opening the file in read mode
    fp = fopen("example.txt", "r");

    // Reading from the file and printing it to the console
    printf("File contents:\n");
    char c = fgetc(fp);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fp);
    }

    // Closing the file
    fclose(fp);

    return 0;
}