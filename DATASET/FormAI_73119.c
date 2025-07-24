//FormAI DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h> // standard input/output library
#include <stdlib.h> // standard library
#include <string.h> // string library

int main() {

    printf("Wow, I cannot believe I am about to write a C program to handle a file!\n");
    printf("This is going to be awesome!\n");

    // create a file pointer
    FILE *fp;

    // open file for writing
    fp = fopen("myFile.txt", "w");

    // check if file was opened successfully
    if (fp == NULL) {
        printf("Oh no! The file could not be opened!\n");
        printf("I better fix this error before proceeding!\n");
        exit(1);
    } else {
        printf("Yes! The file was successfully opened!\n");
    }

    // write to file
    fprintf(fp, "I am so excited to be writing to this file!\n");
    fprintf(fp, "I never imagined I would be able to do this!\n");

    // close file
    fclose(fp);

    printf("Now, let's see what's inside the file...\n");

    // open file for reading
    fp = fopen("myFile.txt", "r");

    // check if file was opened successfully
    if (fp == NULL) {
        printf("Oh no! The file could not be opened for reading!\n");
        printf("I better fix this error before proceeding!\n");
        exit(1);
    } else {
        printf("Yes! The file was successfully opened for reading!\n");
    }

    // read from file
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    // close file
    fclose(fp);

    printf("Wow, I cannot believe it! I successfully handled a file!\n");
    printf("I am so proud of myself!\n");

    return 0;
}