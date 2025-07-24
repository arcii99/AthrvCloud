//FormAI DATASET v1.0 Category: Error handling ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    FILE *fp;
    char *filename = "example.txt";

    fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    if (fgets(buffer, 256, fp) == NULL) {
        fprintf(stderr, "Error reading file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    int num;
    if (sscanf(buffer, "%d", &num) == -1) {
        fprintf(stderr, "Error converting string to integer: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("The number is: %d\n", num);

    if (fclose(fp) == EOF) {
        fprintf(stderr, "Error closing file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}