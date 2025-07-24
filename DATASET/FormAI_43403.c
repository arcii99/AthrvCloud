//FormAI DATASET v1.0 Category: File handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main(){
    char filename[MAX_LEN];
    char line[MAX_LEN];

    printf("Enter the name of the file to be opened: ");
    gets(filename);

    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    printf("Enter some text to write to the file: ");
    gets(line);

    fprintf(fp, "%s\n", line);

    fclose(fp);

    printf("\nFile written successfully.\n");

    printf("\nReading the file contents:\n");

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LEN, fp)) {
        printf("%s", line);
    }

    fclose(fp);

    printf("\nDone reading the file.\n");

    return 0;
}