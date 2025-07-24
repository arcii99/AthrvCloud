//FormAI DATASET v1.0 Category: Error handling ; Style: bold
#include <stdio.h>
#include <stdlib.h>

void error_func(char *file, int line, char *message) {
    fprintf(stderr, "\033[1;31mError in %s:%d: %s\033[0m\n", file, line, message);
    exit(EXIT_FAILURE);
}

int main() {
    FILE *fp;
    char *filename = "non_existent_file.txt";
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        error_func(__FILE__, __LINE__, "File not found");
    }
    
    int num = atoi("not_a_number");
    if (num == 0) {
        error_func(__FILE__, __LINE__, "Invalid integer conversion");
    }
    
    char *ptr = malloc(sizeof(char) * -1);
    if (ptr == NULL) {
        error_func(__FILE__, __LINE__, "Memory allocation failed");
    }
    
    int result = 10 / 0;
    if (result == 0) {
        error_func(__FILE__, __LINE__, "Division by zero");
    }
    
    printf("All error checks passed successfully!\n");
    
    return 0;
}