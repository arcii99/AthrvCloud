//FormAI DATASET v1.0 Category: File handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[30], content[100];

    printf("Enter the name of the file to write: ");
    scanf("%s", filename);

    printf("Enter the content to write in the file: ");
    scanf("%s", content);

    file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fputs(content, file);

    printf("Content has been written to the file successfully.\n");

    fclose(file);

    return 0;
}