//FormAI DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include <stdio.h>

// Function to read text from a file
char* read_text(char* filename) {
    FILE *fp;
    char *buffer = NULL;
    int length;

    fp = fopen(filename, "r");

    if (fp) {
        fseek(fp, 0, SEEK_END);
        length = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        buffer = (char*)malloc(length * sizeof(char));

        if (buffer) {
            fread(buffer, sizeof(char), length, fp);
        }

        fclose(fp);
    }

    return buffer;
}

// Function to write text to a file
void write_text(char* filename, char* text) {
    FILE *fp;

    fp = fopen(filename, "w");

    if (fp) {
        fprintf(fp, "%s", text);
        fclose(fp);
    }
}

int main() {
    char* filename = "example.txt";
    char* text = "This is an example file.\nIt is used to demonstrate file handling in C.\n";
    char* read = read_text(filename);

    if (read) {
        printf("The contents of %s are:\n%s", filename, read);
        free(read);
    } else {
        printf("Failed to read from %s\n", filename);
    }

    write_text(filename, text);

    printf("Wrote the following to %s:\n%s", filename, text);

    return 0;
}