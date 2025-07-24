//FormAI DATASET v1.0 Category: File handling ; Style: accurate
#include <stdio.h>

#define MAX_SIZE 100

int main() {
    FILE *fp;
    char data[MAX_SIZE];

    // Open the file for reading
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read data from the file
    fgets(data, MAX_SIZE, fp);

    // Close the file
    fclose(fp);

    // Perform operations on the data
    printf("The data in the file is: %s\n", data);

    return 0;
}