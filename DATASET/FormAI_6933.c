//FormAI DATASET v1.0 Category: File handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp; // Declare file pointer
    int num = 52;
    char str[] = "This is a C file handling example program.";

    // Create file and Write Integer Data to File
    fp = fopen("example.txt", "w");
    if(fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }
    fprintf(fp, "The value of num is: %d\n", num);
    fclose(fp); // Close file

    // Append the String to the file
    fp = fopen("example.txt", "a");
    if(fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }
    fprintf(fp, "%s", str);
    fclose(fp);

    // Read data from file
    fp = fopen("example.txt", "r");
    if(fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }
    else {
        int numFromFile;
        char strFromFile[100];
        fscanf(fp, "The value of num is: %d\n", &numFromFile);
        fgets(strFromFile, 100, fp);
        printf("%s%d\n", strFromFile, numFromFile); // Output data
        fclose(fp);
    }

    return 0;
}