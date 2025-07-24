//FormAI DATASET v1.0 Category: Error handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    FILE *fp;
    char *filename = "nonexistent.txt";
    char buffer[255];

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: %d\n", errno);
        perror("Error");
        exit(EXIT_FAILURE);
    }

    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    } else {
        if (feof(fp)) {
            printf("End of file reached\n");
        } else {
            printf("Error occurred: %d\n", errno);
            perror("Error");
        }
    }

    fclose(fp);

    return EXIT_SUCCESS;
}