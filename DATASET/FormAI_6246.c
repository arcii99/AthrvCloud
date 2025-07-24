//FormAI DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>

int main() {
    FILE *fp1;
    FILE *fp2;
    char c1, c2;
    fp1 = fopen("file1.txt", "r");
    fp2 = fopen("file2.txt", "w");
    if (fp1 == NULL || fp2 == NULL) {
        printf("Some error occurred!");
        return 1;
    }
    c1 = fgetc(fp1);
    while (c1 != EOF) {
        if (c1 == ' ' || c1 == '\t') {
            fputc(c1, fp2);
            while (c1 == ' ' || c1 == '\t') {
                c1 = fgetc(fp1);
            }
            continue;
        }
        c2 = fgetc(fp1);
        while (c2 != EOF && c2 != ' ' && c2 != '\t') {
            c1 = c2;
            fputc(c1, fp2);
            c2 = fgetc(fp1);
        }
        fputc(' ', fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}