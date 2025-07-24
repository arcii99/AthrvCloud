//FormAI DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char ch;

    fp = fopen("puzzle.txt", "w");
    fprintf(fp, "O~Df_20|j3?trV#lQ'kZpM:4");
    fclose(fp);

    fp = fopen("puzzle.txt", "r");
    if(fp == NULL) {
        printf("Error: File does not exist!");
        exit(1);
    }

    printf("Decrypt this message to solve the puzzle: ");
    while(ch != EOF) {
        ch = fgetc(fp);
        if(ch >= 65 && ch <= 90) {
            ch = (char)((int)ch + 32);
        } else if(ch >= 97 && ch <= 122) {
            ch = (char)((int)ch - 32);
        }
        printf("%c", ch);
    }
    printf("\n");
    fclose(fp);

    return 0;
}