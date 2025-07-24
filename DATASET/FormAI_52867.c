//FormAI DATASET v1.0 Category: File system simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, k;
    FILE *fptr;
    char filename[15];

    printf("Enter filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, "w");

    if (fptr == NULL) {
        printf("Error creating file.\n");
        exit(1);
    }

    printf("File created successfully.\n");

    printf("\nEnter three integers separated by comma: ");
    scanf("%d,%d,%d", &i, &j, &k);

    fprintf(fptr, "%d,%d,%d\n", i, j, k);
    fclose(fptr);

    printf("Data written to file.\n");

    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Error reading file.\n");
        exit(1);
    }

    fscanf(fptr, "%d,%d,%d", &i, &j, &k);

    printf("\nData retrieved from file:\n");
    printf("i = %d\n", i);
    printf("j = %d\n", j);
    printf("k = %d\n", k);

    fclose(fptr);

    return 0;
}