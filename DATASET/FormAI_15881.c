//FormAI DATASET v1.0 Category: File Encyptor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY '!'

int main() {
    char filename[100], ch;
    FILE *fp;

    printf("Enter filename to encrypt: ");
    scanf("%s", filename);

    fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Error opening file.");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        fseek(fp, -1L, SEEK_CUR);
        fputc(ch ^ KEY, fp);
    }

    fclose(fp);
    printf("File encrypted successfully.");

    return 0;
}