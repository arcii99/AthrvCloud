//FormAI DATASET v1.0 Category: File handling ; Style: protected
#include <stdio.h>

#define FILE_PATH "my_file.txt"
#define MAX_CHAR 50

int main() {
    FILE *fp;
    char str[MAX_CHAR];

    fp = fopen(FILE_PATH, "r");

    if (fp == NULL) {
        printf("Failed to open file.");
        return 0;
    }

    while (fgets(str, MAX_CHAR, fp) != NULL) {
        printf("%s", str);
    }

    fclose(fp);

    return 0;
}