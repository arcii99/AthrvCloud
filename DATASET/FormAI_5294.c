//FormAI DATASET v1.0 Category: Error handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void print_error(char* function, int line_num) {
    printf("[%s:%d] ERROR: %s\n", function, line_num, strerror(errno));
}

int main() {
    char* file_name = "nonexistent_file.txt";
    FILE* fp = fopen(file_name, "r");

    if (fp == NULL) {
        print_error(__func__, __LINE__);
        exit(EXIT_FAILURE);
    }

    int num1, num2;
    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        print_error(__func__, __LINE__);
        exit(EXIT_FAILURE);
    }

    if (num2 == 0) {
        printf("ERROR: Division by zero not allowed.\n");
        exit(EXIT_FAILURE);
    }

    int result = num1 / num2;
    printf("%d divided by %d is %d\n", num1, num2, result);

    if (fclose(fp) != 0) {
        print_error(__func__, __LINE__);
        exit(EXIT_FAILURE);
    }

    return 0;
}