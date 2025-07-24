//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_LINE_LEN 100

int main(int argc, char *argv[])
{
    FILE *fp;
    char line[MAX_LINE_LEN];
    char *token[MAX_COLS];
    int num_cols = 0;
    int i, j;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        /* Split the line into tokens */
        token[0] = strtok(line, ",");
        num_cols = 1;
        while ((token[num_cols] = strtok(NULL, ",")) != NULL) {
            num_cols++;
        }

        /* Print out the tokens */
        for (i = 0; i < num_cols; i++) {
            printf("%s\t", token[i]);
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}