//FormAI DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>

int main(){
    FILE *fp;
    char line[100];

    // write data to a file
    fp = fopen("example.txt", "w");
    if(fp == NULL) {
        printf("Error opening file for writing.");
        return 1;
    }
    fputs("Hello, world!\n", fp);
    fclose(fp);

    // read data from a file
    fp = fopen("example.txt", "r");
    if(fp == NULL) {
        printf("Error opening file for reading.");
        return 1;
    }
    while(fgets(line, 100, fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);

    // append data to a file
    fp = fopen("example.txt", "a");
    if(fp == NULL) {
        printf("Error opening file for appending.");
        return 1;
    }
    fputs("Goodbye, world!\n", fp);
    fclose(fp);

    // display updated data in the file
    fp = fopen("example.txt", "r");
    if(fp == NULL) {
        printf("Error opening file for reading.");
        return 1;
    }
    while(fgets(line, 100, fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);

    return 0; 
}