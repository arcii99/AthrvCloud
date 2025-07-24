//FormAI DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>

int main() {

    FILE *fPointer;
    char data[1000];

    // Writing to the file
    fPointer = fopen("example.txt", "w");
    fprintf(fPointer, "This is an example file.\n");
    fprintf(fPointer, "It is created using C file handling.\n");
    fclose(fPointer);

    // Reading from the file
    fPointer = fopen("example.txt", "r");
    printf("The contents of the file are:\n");
    while(fgets(data, 1000, fPointer)) {
        printf("%s", data);
    }
    fclose(fPointer);

    return 0;
}