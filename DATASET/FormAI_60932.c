//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 100

int main(int argc, char *argv[]) {
    char buffer[BUFFER_LENGTH];
    char *token;

    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }

    FILE *fp;
    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error opening file \"%s\".\n", argv[1]);
        exit(1);
    }

    while (fgets(buffer, BUFFER_LENGTH, fp)) {
        token = strtok(buffer, ",");

        while (token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, ",");
        }

        printf("\n");
    }

    fclose(fp);

    return 0;
}