//FormAI DATASET v1.0 Category: Error handling ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

extern int errno;

int main() {
    FILE *file;
    int number;

    file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("Unable to open the file. Error No %d\n", errno);
        perror("Error Message");
        exit(EXIT_FAILURE);
    }

    printf("The contents of the file are: ");

    while(fscanf(file, "%d", &number) == 1) {
        printf("%d ", number);
    }

    if (feof(file) == 0) {
        printf("\nError reading from the file. Error No %d\n", errno);
        perror("Error Message");
        exit(EXIT_FAILURE);
    }

    if (fclose(file) != 0) {
        printf("\nError closing the file. Error No %d\n", errno);
        perror("Error Message");
        exit(EXIT_FAILURE);
    }

    return 0;
}