//FormAI DATASET v1.0 Category: Error handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

static void cleanup(void) {
    puts("Cleanup");
}

int main(int argc, char *argv[])
{
    if(argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    atexit(cleanup);

    FILE *fp = fopen(argv[1], "r");

    if(fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;

    printf("Reading contents of file %s:\n", argv[1]);

    while(getline(&line, &len, fp) != -1) {
        printf("%s", line);
    }

    free(line);
    fclose(fp);

    return 0;
}