//FormAI DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>

int main() {
    // initialize a file pointer
    FILE *fp;

    // open the file in write mode
    fp = fopen("example.txt", "w");

    // check if the file was opened successfully
    if(fp == NULL) {
        printf("Error opening file!");
        return 1;
    }

    // write a message to the file
    fprintf(fp, "Hello, world!");

    // close the file
    fclose(fp);

    // open the file in read mode
    fp = fopen("example.txt", "r");

    // check if the file was opened successfully
    if(fp == NULL) {
        printf("Error opening file!");
        return 1;
    }

    // read the message from the file
    char message[100];
    fgets(message, 100, fp);

    // print the message to the console
    printf("Message: %s", message);

    // close the file
    fclose(fp);

    return 0;
}