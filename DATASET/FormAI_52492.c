//FormAI DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>

int main() {
    FILE *fp; // File pointer
    char filename[] = "example_file.txt";
    char data[] = "Hello, World!"; // Data to write to file
    char buffer[20]; // Buffer for reading data from file

    // Writing data to file
    fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error: Could not create file");
        return 1;
    }
    fprintf(fp, "%s", data);
    fclose(fp);

    // Reading data from file
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: Could not open file");
        return 1;
    }
    fgets(buffer, 20, fp);
    printf("Data read from file: %s", buffer);
    fclose(fp);

    return 0;
}