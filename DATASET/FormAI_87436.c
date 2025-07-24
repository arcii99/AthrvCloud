//FormAI DATASET v1.0 Category: Error handling ; Style: brave
#include <stdio.h>

void error(char* message) {
    printf("\n[ERROR] %s\n", message);
    exit(1);
}

int main() {
    FILE *fp;
    char file_name[100], c;
    int num, x, y, res;

    printf("Enter a file name: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "r");

    if(fp == NULL) {
        error("File could not be opened!");
    }

    printf("Enter two numbers to divide: ");
    res = scanf("%d %d", &x, &y);

    if(res != 2) {
        error("Invalid input entered for numbers!");
    }

    if(y == 0) {
        error("Division by zero not allowed!");
    }

    num = x / y;
    printf("The result of %d divided by %d is: %d\n", x, y, num);

    fclose(fp);
    return 0;
}