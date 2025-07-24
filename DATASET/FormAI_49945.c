//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    char sanitized_input[100];
    int i, j = 0;
    
    printf("Oh, how my heart doth leap with joy at thy command. Pray, tell me, what is thy input?\n");
    fgets(input, 100, stdin);
    
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '<' || input[i] == '>' || input[i] == '&' || input[i] == '"' || input[i] == '\'') {
            continue;
        }
        else {
            sanitized_input[j] = input[i];
            j++;
        }
    }
    sanitized_input[j] = '\0';

    printf("Verily, thy input has been sanitized to:\n%s", sanitized_input);

    return 0;
}