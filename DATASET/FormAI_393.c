//FormAI DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int num[5] = {1, 2, 3, 4, 5};
    int i;

    fp = fopen("numbers.txt", "w");

    if (fp == NULL) {
        printf("Oh no! Cannot open the file. Goodbye!\n");
        exit(1);
    }

    for (i = 0; i < 5; i++) {
        fprintf(fp, "%d ", num[i]);
    }

    printf("File successfully written! Let's read it.\n");

    fclose(fp);

    fp = fopen("numbers.txt", "r");

    if (fp == NULL) {
        printf("Oh no! Cannot open the file. Goodbye!\n");
        exit(1);
    }

    printf("Here are the numbers from the file: ");

    for (i = 0; i < 5; i++) {
        fscanf(fp, "%d", &num[i]);
        printf("%d ", num[i]);
    }

    printf("Aren't they lovely?\n");

    fclose(fp);

    return 0;
}