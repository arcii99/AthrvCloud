//FormAI DATASET v1.0 Category: Error handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main(int argc, char *argv[]) {
    FILE *fp;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        error("Cannot open file");
    }

    char buffer[1024];
    int num;

    printf("Enter a number: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        error("Cannot read from stdin");
    }

    errno = 0;
    num = strtol(buffer, NULL, 10);
    if (errno != 0) {
        error("Invalid number entered");
    }

    if (num < 0 || num > 100) {
        fprintf(stderr, "Number must be between 0 and 100\n");
        exit(1);
    }

    printf("Your number: %d\n", num);

    if (fclose(fp) == EOF) {
        error("Cannot close file");
    }

    return 0;
}