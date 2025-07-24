//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: active
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void sanitizeString(char *inputString, size_t length);
void sanitizeInt(int *inputInt);

int main() {
    char inputString[100];
    int inputInt;

    printf("Enter a string: ");
    fgets(inputString, 100, stdin);
    sanitizeString(inputString, strlen(inputString));

    printf("Enter an integer: ");
    scanf("%d", &inputInt);
    sanitizeInt(&inputInt);

    printf("Your sanitized string is: %s\n", inputString);
    printf("Your sanitized integer is: %d\n", inputInt);

    return 0;
}

void sanitizeString(char *inputString, size_t length) {
    for (int i = 0; i < length; i++) {
        if (isspace(inputString[i])) {
            inputString[i] = ' ';
        } else if (isalnum(inputString[i]) == 0) {
            inputString[i] = '.';
        }
    }
}

void sanitizeInt(int *inputInt) {
    if (*inputInt < 0) {
        *inputInt *= -1;
    }
}