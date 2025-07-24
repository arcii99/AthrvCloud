//FormAI DATASET v1.0 Category: File Synchronizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

/* This program demonstrates how to synchronize two files using C */

int main() {
    FILE *fp1, *fp2;
    char c1, c2;
    char file1[100], file2[100];

    printf("Enter file 1 name: ");
    scanf("%s", file1);

    printf("Enter file 2 name: ");
    scanf("%s", file2);

    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("File(s) not found!");
        exit(0);
    }

    while ((c1 = fgetc(fp1)) != EOF && (c2 = fgetc(fp2)) != EOF) {
        if (c1 == c2) {
            // if characters are same in both files, skip to next character
            continue;
        } else {
            // if characters are different in both files, make them same
            fseek(fp1, -1, SEEK_CUR);
            fputc(c2, fp1);
        }
    }

    fclose(fp1);
    fclose(fp2);

    printf("Files synchronized successfully!");

    return 0;
}