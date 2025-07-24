//FormAI DATASET v1.0 Category: File handling ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    FILE *fp;
    char ch;
    int num_of_lines = 0, num_of_chars = 0;

    fp = fopen("sample.txt", "r");
    if(fp == NULL) {
        printf("File does not exist\n");
        exit(0);
    }

    while((ch = fgetc(fp)) != EOF) {
        if(ch == '\n') {
            num_of_lines++;
        }
        num_of_chars++;
    }

    printf("Number of lines in the file: %d\n", num_of_lines);
    printf("Number of characters in the file: %d\n", num_of_chars);

    fclose(fp);

    return 0;
}