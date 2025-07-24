//FormAI DATASET v1.0 Category: Text processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program takes a text file as input and converts the first letter of each sentence to uppercase

int main() {
    char file_name[50];
    char buffer[5000];
    int i;
    FILE *file_pointer;

    printf("Please enter the name of the file to be processed: ");
    scanf("%s", file_name);

    file_pointer = fopen(file_name, "r");
    if (file_pointer == NULL) {
        printf("Error opening file %s", file_name);
        exit(1);
    }

    // Read file contents into buffer
    fread(buffer, sizeof(buffer), 1, file_pointer);

    // Loop through buffer and convert first letter of each sentence to uppercase
    for (i = 0; i < strlen(buffer); i++) {
        if (buffer[i] == '.' || buffer[i] == '!' || buffer[i] == '?') {
            while (buffer[i+1] == ' ') { // skip spaces after punctuation
                i++;
            }
            i++;
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = buffer[i] - 32;
            }
        }
    }

    printf("Contents of processed file:\n%s", buffer);

    fclose(file_pointer);

    return 0;
}