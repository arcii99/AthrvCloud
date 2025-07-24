//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Alan Touring
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, char *argv[])
{
    char *filename = argv[1];
    char word[100];
    int count = 0;
    FILE *fp;

    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Cannot open file: %s\n", filename);
        return 1;
    }

    while (fscanf(fp, "%s", word) != EOF) {
        count++;
    }

    fclose(fp);

    printf("Number of words in %s: %d\n", filename, count);

    return 0;
}