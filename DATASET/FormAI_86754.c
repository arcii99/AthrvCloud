//FormAI DATASET v1.0 Category: Pattern printing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int min, max, mid;
    char fill;

    if (argc != 4) {
        printf("Usage: ./c-pattern <min> <max> <fill>\n");
        printf("Example: ./c-pattern 1 10 *\n");
        exit(1);
    }

    min = atoi(argv[1]);
    max = atoi(argv[2]);
    fill = argv[3][0];

    mid = (min + max) / 2;

    for (int i = min; i <= max; i++) {
        for (int j = min; j <= max; j++) {
            if (i == min || i == mid || i == max) {
                printf("%c", fill);
            } else if (j == min || j == mid || j == max) {
                printf("%c", fill);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}