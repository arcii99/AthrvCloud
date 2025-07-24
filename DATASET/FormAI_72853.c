//FormAI DATASET v1.0 Category: Error handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    int num1, num2, result;

    printf("Enter two numbers to divide: ");
    scanf("%d %d", &num1, &num2);

    if(num2 == 0) {
        fprintf(stderr, "ERROR: Cannot divide by 0.\n");
        exit(EXIT_FAILURE);
    }

    result = num1 / num2;
    printf("%d / %d = %d\n", num1, num2, result);

    FILE *fp;
    fp = fopen("nonexistent.txt", "r");
    if(fp == NULL) {
        if(errno == ENOENT) {
            perror("ERROR");
            printf("The file does not exist.\n");
        } else {
            perror("ERROR");
            printf("Unknown error occurred.\n");
        }
    }

    return 0;
}