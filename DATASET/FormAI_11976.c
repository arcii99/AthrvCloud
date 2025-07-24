//FormAI DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: No input file specified\n");
        exit(1);
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error");
        exit(1);
    }

    char line[1024];
    int line_num = 1;
    while (fgets(line, 1024, fp)) {
        if (line[0] == '#') {
            printf("Skipping comment on line %d\n", line_num);
            continue;
        }
        int num = atoi(line);
        if (num == 0 && line[0] != '0') {
            fprintf(stderr, "Error: Non-numeric value on line %d\n", line_num);
            exit(1);
        }
        printf("%d\n", num);
        line_num++;
    }

    fclose(fp);
    return 0;
}