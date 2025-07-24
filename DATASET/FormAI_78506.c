//FormAI DATASET v1.0 Category: File handling ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    FILE *file;

    // open file for writing
    file = fopen("example.txt", "w");

    // check if file opened successfully
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // write to the file
    fprintf(file, "This is an example file.\n");
    fprintf(file, "It is created using C file handling.\n");

    // close the file
    fclose(file);

    // open file for reading
    file = fopen("example.txt", "r");

    // check if file opened successfully
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // read from the file
    char buffer[100];
    while (fgets(buffer, 100, file) != NULL) {
        printf("%s", buffer);
    }

    // close the file
    fclose(file);

    return 0;
}