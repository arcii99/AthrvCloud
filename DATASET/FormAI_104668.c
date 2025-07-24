//FormAI DATASET v1.0 Category: Error handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void print_error(char *error_type) {
    fprintf(stderr, "Error: %s\n", error_type);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char *filename = argv[1];
    int number, sum = 0;

    if (argc != 2) {
        print_error("Invalid arguments");
    }

    fp = fopen(filename, "r");
    if (fp == NULL) {
        char error[100];
        sprintf(error, "Unable to open file: %s", strerror(errno));
        print_error(error);
    }
    
    while (fscanf(fp, "%d", &number) == 1) {
        if (number < 0) {
            fclose(fp);
            print_error("Negative number found");
        }
        sum += number;
    }
    
    if (!feof(fp)) {
        fclose(fp);
        print_error("Error while reading file");
    }
    
    printf("Sum of numbers in %s is %d\n", filename, sum);
    fclose(fp);

    return 0;
}