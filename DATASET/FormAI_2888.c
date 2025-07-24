//FormAI DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {

    // define file pointer and variable to store user input
    FILE *fp;
    char user_input[256];

    // open file for writing
    fp = fopen("example.txt", "w");

    // check if file was successfully opened
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // get user input and write to file
    printf("Please enter some text to write to the file: ");
    fgets(user_input, 256, stdin);
    fprintf(fp, "%s", user_input);

    // close file
    fclose(fp);

    // open file for reading
    fp = fopen("example.txt", "r");

    // check if file was successfully opened
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // read from file and output to console
    printf("The following text was read from the file: ");
    while(fgets(user_input, 256, fp)) {
        printf("%s", user_input);
    }

    // close file
    fclose(fp);

    return 0;
}