//FormAI DATASET v1.0 Category: Syntax parsing ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[100];
    char tokens[100][100];
    int i, j, k;
    int num_tokens = 0;

    printf("Enter a C syntax expression: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Extract tokens from input expression
    for (i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n') {
            continue;
        }
        else if (buffer[i] == '(' || buffer[i] == ')' || buffer[i] == '{' || buffer[i] == '}' || buffer[i] == '[' || buffer[i] == ']') {
            tokens[num_tokens][0] = buffer[i];
            tokens[num_tokens][1] = '\0';
            num_tokens++;
        }
        else {
            j = i;
            while (buffer[j] != ' ' && buffer[j] != '\t' && buffer[j] != '\n' && buffer[j] != '(' && buffer[j] != ')' && buffer[j] != '{' && buffer[j] != '}' && buffer[j] != '[' && buffer[j] != ']') {
                tokens[num_tokens][j - i] = buffer[j];
                j++;
            }
            tokens[num_tokens][j - i] = '\0';
            i = j - 1;
            num_tokens++;
        }
    }

    // Print out tokens
    printf("\nTokens:\n");
    for (k = 0; k < num_tokens; k++) {
        printf("%s\n", tokens[k]);
    }

    return 0;
}