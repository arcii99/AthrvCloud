//FormAI DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>

int main() {
    FILE *fp;

    // Opening file in write mode
    fp = fopen("example.txt", "w");

    // Checking if file is opened successfully or not
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Writing data to the file
    fprintf(fp, "Hello World!\n");
    fprintf(fp, "My name is Jane.\n");
    fprintf(fp, "I am a chatbot.\n");

    // Closing the file
    fclose(fp);

    // Reopening file in read mode
    fp = fopen("example.txt", "r");

    // Checking if file is opened successfully or not
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Reading data from the file and printing it on the console
    char buffer[100];
    while (fgets(buffer, 100, fp) != NULL) {
        printf("%s", buffer);
    }

    // Closing the file
    fclose(fp);

    return 0;
}