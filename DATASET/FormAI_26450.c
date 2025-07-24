//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Alan Touring
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[1000], delimiter;
    int i, length, flag = 0, int_flag = 0, float_flag = 0;
    printf("Enter a C statement:\n");
    fgets(input, 1000, stdin);
    length = strlen(input);

    for(i = 0; i < length; i++) {
        if(input[i] == ' ') {
            continue;
        } else if(isalpha(input[i])) {
            flag = 1;
        } else if(input[i] == '(' || input[i] == ')' || input[i] == ',' || input[i] == '[' || input[i] == ']') {
            delimiter = input[i];
            flag = 2;
        } else if(isdigit(input[i])) {
            if(float_flag == 0 && input[i] == '.') {
                float_flag = 1;
            } else if(float_flag == 1 && input[i] == '.') {
                printf("Invalid input: multiple decimal points\n");
                return 0;
            }
            int_flag = 1;
        } else if(input[i] == '.' && int_flag == 0) {
            printf("Invalid input: decimal point before any digits\n");
            return 0;
        } else {
            printf("Invalid character: %c\n", input[i]);
            return 0;
        }
    }

    if(flag == 1) {
        printf("Valid identifier\n");
    } else if(flag == 2) {
        printf("Valid delimiter: %c\n", delimiter);
    } else {
        printf("Invalid input\n");
    }

    return 0;
}