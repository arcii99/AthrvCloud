//FormAI DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>

int main() {
    // Open the file in write mode
    FILE *fp = fopen("example.txt", "w");

    // Check if file opened successfully
    if(fp == NULL) {
        printf("Failed to open file.\n");
        return 0;
    }

    // Write some text to file
    fprintf(fp, "This is an example file.\nYou can write anything you want here.\n");

    // Close the file
    fclose(fp);

    // Open the file in read mode
    fp = fopen("example.txt", "r");

    // Check if file opened successfully
    if(fp == NULL) {
        printf("Failed to open file.\n");
        return 0;
    }

    // Read the file line by line
    char buffer[256];
    while(fgets(buffer, 256, fp)) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(fp);

    return 0;
}