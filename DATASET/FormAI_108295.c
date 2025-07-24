//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INITIAL_SIZE 50
#define SIZE_INCREMENT 25

char* concatenate_strings(char* str1, char* str2) {
    int total_length = strlen(str1) + strlen(str2);
    char* result_string = (char*)malloc(total_length + 1);
    if (result_string == NULL) {
        printf("Error: Failed to allocate memory!\n");
        exit(1);
    }

    int index = 0;
    while (*str1 != '\0') {
        result_string[index++] = *str1++;
    }

    while (*str2 != '\0') {
        result_string[index++] = *str2++;
    }

    result_string[index] = '\0';
    return result_string;
}

int main() {
    char* first_string = "Hello, ";
    char* second_string = "World!";
    char* result = concatenate_strings(first_string, second_string);
    printf("%s\n", result);

    free(result);
    return 0;
}