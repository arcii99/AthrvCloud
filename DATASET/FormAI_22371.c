//FormAI DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    char filename[] = "data.txt";
    FILE *file_pointer;

    file_pointer = fopen(filename, "w");

    if (file_pointer == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }

    printf("Enter %d integers separated by commas:\n", MAX_SIZE);

    int array[MAX_SIZE];
    char buffer[100];
    fgets(buffer, 100, stdin);

    char *token = strtok(buffer, ",");
    int i = 0;
    while (token != NULL && i < MAX_SIZE) {
        array[i++] = atoi(token);
        token = strtok(NULL, ",");
    }

    for (int j = 0; j < i; j++) {
        fprintf(file_pointer, "%d\n", array[j]);
    }

    fclose(file_pointer);

    printf("File written successfully!\n");

    return 0;
}