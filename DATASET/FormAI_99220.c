//FormAI DATASET v1.0 Category: Error handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    FILE *fp;
    char filename[50];
    int num;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Error opening file");
        printf("Error code: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        fprintf(stderr, "Invalid number entered\n");
        exit(EXIT_FAILURE);
    }

    int result = 100 / num;
    printf("Result = %d\n", result);

    fclose(fp);
    return 0;
}