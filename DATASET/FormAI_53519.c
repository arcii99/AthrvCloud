//FormAI DATASET v1.0 Category: System administration ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

    int fd;
    char *input;
    size_t size = 100;
    char buffer[100];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }

    printf("File opened successfully\n");

    printf("Enter text to append: ");
    input = (char *) malloc(size * sizeof(char));
    getline(&input, &size, stdin);

    strncat(input, "\n", 1);

    if(write(fd, input, strlen(input)) < 0) {
        fprintf(stderr, "Error writing to file\n");
        exit(EXIT_FAILURE);
    }

    printf("Text added successfully\n");

    close(fd);
    free(input);

    return 0;
}