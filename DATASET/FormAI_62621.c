//FormAI DATASET v1.0 Category: File handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// function to recursively read and print files
void read_and_print_file(FILE *file) {

    char ch;

    // read and print character by character until the end of file
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    // move the cursor to the beginning of the file
    rewind(file);

    // check if the file has a subfile
    if (fgetc(file) == 's') {
        // move the cursor to the beginning of the file
        rewind(file);

        // open the subfile recursively
        FILE *subfile = fopen("subfile.txt", "r");
        read_and_print_file(subfile);
        fclose(subfile);
    }
}

int main() {

    // open the file
    FILE *file = fopen("file.txt", "r");

    // check if the file exists
    if (file == NULL) {
        printf("File not found.");
        exit(1);
    }

    // recursively read and print the file
    read_and_print_file(file);

    // close the file
    fclose(file);

    return 0;
}