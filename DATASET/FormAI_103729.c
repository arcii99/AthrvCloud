//FormAI DATASET v1.0 Category: Data mining ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int x, y;
    float z;

    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", argv[1]);
        exit(1);
    }

    printf("Data:\n");
    printf(" x | y | z\n");
    printf("---+---+-------\n");

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        sscanf(line, "%d,%d,%f", &x, &y, &z);
        printf("%2d |%2d | %.2f\n", x, y, z);
    }

    fclose(fp);

    return 0;
}