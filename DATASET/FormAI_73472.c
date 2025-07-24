//FormAI DATASET v1.0 Category: Log analysis ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("log.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "error") != NULL) {
            printf("%s", line);
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }
    exit(0);
}