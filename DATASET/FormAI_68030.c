//FormAI DATASET v1.0 Category: Error handling ; Style: irregular
#include <stdio.h>

int main(void) {
    printf("Welcome to the Error Handling Example Program!\n\n");
    int x = 5;
    int y = 0;

    if (y == 0) {
        printf("Error: Division by zero is not allowed!\n");
        return 1;
    }

    int result = x / y;

    printf("The result of %d divided by %d is: %d\n", x, y, result);

    char* string1 = "Hello world!";
    char* string2 = NULL;

    if (string2 == NULL) {
        printf("Error: The second string is null!\n");
        return 1;
    }

    strcpy(string2, string1);
    printf("String 2: %s\n", string2);

    FILE* fp = fopen("nonexistent_file.txt", "r");

    if (fp == NULL) {
        printf("Error: The file could not be opened!\n");
        return 1;
    }

    fclose(fp);

    printf("All errors handled successfully!\n");

    return 0;
}