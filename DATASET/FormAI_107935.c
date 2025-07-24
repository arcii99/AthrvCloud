//FormAI DATASET v1.0 Category: File Synchronizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the C File Synchronizer!\n");

    char filename1[50];
    char filename2[50];

    printf("Enter filename 1: ");
    scanf("%s", filename1);

    printf("Enter filename 2: ");
    scanf("%s", filename2);

    printf("Synchronizing...\n");

    FILE *file1 = fopen(filename1, "r");
    FILE *file2 = fopen(filename2, "w");

    if (!file1) {
        printf("Could not open file '%s'\n", filename1);
        return 1;
    }

    if (!file2) {
        printf("Could not open file '%s'\n", filename2);
        return 1;
    }

    char c;
    while ((c = fgetc(file1)) != EOF) {
        fputc(c, file2);
    }

    fclose(file1);
    fclose(file2);

    printf("Done! Files synchronized.\n");

    return 0;
}