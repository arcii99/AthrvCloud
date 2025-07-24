//FormAI DATASET v1.0 Category: File handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Open a file for reading and writing
    FILE* fp = fopen("data.txt", "w+");
    if (fp == NULL) {
        printf("Error: Failed to open file.\n");
        return -1;
    }

    // Write some data to the file
    char* data = "Hello, world!";
    int len = strlen(data);
    fwrite(data, sizeof(char), len, fp);
    fseek(fp, 0, SEEK_SET); // Move the file pointer back to the beginning

    // Read the data back from the file
    char* buffer = calloc(len+1, sizeof(char));
    fread(buffer, sizeof(char), len, fp);
    printf("Data in the file: %s\n", buffer);

    // Close the file
    fclose(fp);

    return 0;
}