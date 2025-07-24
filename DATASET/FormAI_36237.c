//FormAI DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {

    FILE *fp;
    char path[100];
    int lineNumber = 0;
    int flag = 0;
    char search[50];

    printf("Enter a file path: ");
    scanf("%s", path);

    printf("Enter the word to be searched: ");
    scanf("%s", search);

    fp = fopen(path, "r");

    if(fp == NULL) {
        printf("\nError opening file: %s\n", strerror(errno));
        exit(1);
    }

    char line[256];
    while(fgets(line, sizeof(line), fp)) {
        lineNumber++;

        if(strstr(line, search) != NULL) {
            printf("\nLine %d : %s\n", lineNumber, line);
            flag = 1;
        }
    }

    if(flag == 0) {
        printf("\n%s not found in file.\n", search);
        exit(1);
    }

    fclose(fp);
    return 0;
}