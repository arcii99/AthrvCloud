//FormAI DATASET v1.0 Category: Data recovery tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS 1000

int main() {
    char data[MAX_CHARS], *filename;
    FILE *fp;

    printf("Enter the name of the file to recover: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File could not be opened.\n");
        exit(0);
    }

    while (fgets(data, MAX_CHARS, fp) != NULL) {
        printf("%s", data);
    }

    fclose(fp);

    return 0;
}