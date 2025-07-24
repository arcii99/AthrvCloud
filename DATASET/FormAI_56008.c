//FormAI DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void handle_error(char* error_msg, int error_code) {
    printf("Error %d: %s\n", error_code, error_msg);
    exit(error_code);
}

int main() {
    FILE* fp;
    char filename[20];
    int num1, num2, result;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if(fp == NULL) {
        handle_error("Unable to open file", 1);
    }

    if(fscanf(fp, "%d %d", &num1, &num2) != 2) {
        handle_error("Invalid file format", 2);
    }

    if(num2 == 0) {
        handle_error("Cannot divide by zero", 3);
    }

    result = num1 / num2;

    printf("%d / %d = %d\n", num1, num2, result);

    fclose(fp);

    return 0;
}