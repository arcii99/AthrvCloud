//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: medieval
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 50

void sanitize(char *input);

int main() {
    char input[MAX_LENGTH];
    printf("Enter your input: ");
    fgets(input, MAX_LENGTH, stdin);
    printf("Your sanitized input is: ");
    sanitize(input);
    printf("%s", input);
    return 0;
}

void sanitize(char *input) {
    int i = 0, j = 0;
    char temp[MAX_LENGTH];
    while (input[i]) {
        if (isalpha(input[i])) {
            temp[j++] = input[i];
        }
        i++;
    }
    temp[j] = '\0';
    strcpy(input, temp);
}