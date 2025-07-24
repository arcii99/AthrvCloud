//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: funny
#include <stdio.h>
#include <string.h>

void sanitize(char *input) {
    int len = strlen(input);
    int i, j = 0;
    char output[len];
    for(i = 0; i < len; i++) {
        if(input[i] < 65 || (input[i] > 90 && input[i] < 97) || input[i] > 122) {
            output[j] = '_';
        } else {
            output[j] = input[i];
        }
        j++;
    }
    strcpy(input, output);
}
int main() {
    char input[50];
    printf("Enter your name to sanitize: ");
    fgets(input, 50, stdin);
    sanitize(input);
    printf("Your sanitized name is: %s\n", input);
    return 0;
}