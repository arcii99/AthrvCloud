//FormAI DATASET v1.0 Category: Data recovery tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[100], ch;
    FILE *fp;
    int count = 0;

    printf("Enter the filename to open for reading: ");
    scanf("%s", filename);

    // open the file for reading
    fp = fopen(filename, "r");

    // check if file exists or not
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        exit(1);
    }

    // read file character by character and count the number of characters
    while ((ch = fgetc(fp)) != EOF) {
        count++;
    }

    rewind(fp); // reposition the file pointer to the beginning of the file

    // allocate memory for the file content
    char *file_content = (char*) malloc((count+1) * sizeof(char));

    // read the file content into the memory and add a null terminator
    fread(file_content, sizeof(char), count, fp);
    file_content[count] = '\0';

    printf("File content:\n%s\n", file_content);

    fclose(fp);
    free(file_content);

    return 0;
}