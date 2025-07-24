//FormAI DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_INP_LEN 1000
#define MAX_TOKENS 1000
#define DELIMITER " ,.!?;\n"

void reverse_string(char *str) {
    char temp;
    int i, j;

    // reverse the string
    for(i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void remove_special_chars(char *str) {
    char *ptr = str;
    while (*ptr != '\0') {
        if (!(*ptr >= 'a' && *ptr <= 'z' || *ptr >= 'A' && *ptr <= 'Z' || *ptr == ' ')) {
            memmove(ptr, ptr + 1, strlen(ptr + 1) + 1);
        }
        else {
            ptr++;
        }
    }
}

int main() {
    char input_str[MAX_INP_LEN];
    char *tokens[MAX_TOKENS];
    int num_tokens = 0;

    printf("Enter a string to manipulate:\n");
    fgets(input_str, MAX_INP_LEN, stdin);

    // Tokenize the input string
    tokens[num_tokens] = strtok(input_str, DELIMITER);
    while (tokens[num_tokens] != NULL) {
        num_tokens++;
        tokens[num_tokens] = strtok(NULL, DELIMITER);
    }

    // Reverse each token and print the result
    printf("Reversed tokens:\n");
    for (int i = 0; i < num_tokens; i++) {
        reverse_string(tokens[i]);
        printf("%s ", tokens[i]);
    }
    printf("\n");

    // Remove special characters and print the result
    printf("String with special characters removed:\n");
    remove_special_chars(input_str);
    printf("%s\n", input_str);

    return 0;
}