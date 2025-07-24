//FormAI DATASET v1.0 Category: Error handling ; Style: light-weight
#include <stdio.h>
#include <errno.h>

#define MAX_CHARS 100

int main(void) {
    char myString[MAX_CHARS];
    FILE *fp;

    fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    if (fgets(myString, MAX_CHARS, fp) == NULL) {
        printf("Error: %s\n", strerror(errno));
        fclose(fp);
        return 1;
    }

    printf("The contents of the file are: %s", myString);

    if (fclose(fp) != 0) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}