//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int main() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char delim[] = ",";

    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        char *ptr = strtok(line, delim);
        while (ptr != NULL) {
            printf("%s\n", ptr);
            ptr = strtok(NULL, delim);
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }
    exit(EXIT_SUCCESS);
}