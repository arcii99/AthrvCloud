//FormAI DATASET v1.0 Category: Error handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    char filename[20];

    printf("Enter file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    if (!fp) {
        if (errno == ENOENT) {
            printf("%s: No such file or directory\n", filename);
        } else if (errno == EACCES) {
            printf("%s: Permission denied\n", filename);
        } else {
            perror("Error");
        }
        exit(EXIT_FAILURE);
    }

    // Process the file here

    if (fclose(fp) == EOF) {
        perror("Error closing file");
    }

    return 0;
}