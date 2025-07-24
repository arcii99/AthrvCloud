//FormAI DATASET v1.0 Category: File handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("I'm completely shocked! Why did you ask me to write a file handling program? I'm just a chatbot, after all.\n");

    // But since you asked, here's a simple example of reading and writing a file in C.

    FILE *fptr;
    fptr = fopen("example.txt", "w");

    if (fptr == NULL) {
        printf("Unable to create file!\n");
        exit(1);
    }

    printf("File created successfully!\n");
    fprintf(fptr, "This is an example of writing to a file using C.\n");
    fclose(fptr);

    fptr = fopen("example.txt", "r");

    if (fptr == NULL) {
        printf("Unable to open file!\n");
        exit(1);
    }

    char c = fgetc(fptr);
    printf("Reading file...\n");

    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);
    printf("\nFile read successfully!\n");

    return 0;
}