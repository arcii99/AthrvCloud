//FormAI DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    FILE *fp;
    int n, sum = 0;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Reading integers from file:\n");
    while (fscanf(fp, "%d", &n) == 1) {
        printf("%d\n", n);
        sum += n;
    }

    fclose(fp);

    printf("Sum of integers: %d\n", sum);

    return 0;
}