//FormAI DATASET v1.0 Category: Error handling ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_error(const char *func_name, int line_num, const char *error_msg) {
    FILE *error_log = fopen("error.log", "a");
    if (!error_log) {
        exit(EXIT_FAILURE);
    }

    fprintf(error_log, "Error in function %s, line %d: %s\n", func_name, line_num, error_msg);
    fclose(error_log);
}

int main() {
    char *str = NULL;
    int num;

    printf("Enter a string: ");
    if (fgets(str, 50, stdin) == NULL) {
        handle_error(__func__, __LINE__, "Failed to read input string");
        exit(EXIT_FAILURE);
    }

    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) {
        handle_error(__func__, __LINE__, "Failed to read input number");
        exit(EXIT_FAILURE);
    }

    if (num <= 0) {
        handle_error(__func__, __LINE__, "Number must be positive");
        exit(EXIT_FAILURE);
    }

    int str_len = strlen(str);
    if (str_len == 0 || str[str_len-1] != '\n') {
        handle_error(__func__, __LINE__, "Invalid input string");
        exit(EXIT_FAILURE);
    }

    printf("The input string is: %s", str);
    printf("The input number is: %d\n", num);

    return 0;
}