//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: careful
#include <stdio.h>
#include <ctype.h>

/* Function to sanitize user input */
void sanitize_input(char *input_str) {
    int i = 0;
    while(input_str[i]) {
        /* Remove leading and trailing white spaces */
        if(i == 0 || input_str[i+1] == '\0') {
            while(isspace(input_str[i])) {
                input_str++;
            }
        }
        if(input_str[i+1] == '\0' && isspace(input_str[i])) {
            input_str[i] = '\0';
            break;
        }
        /* Replace non-alphanumeric characters with space */
        if(!isalnum(input_str[i])) {
            input_str[i] = ' ';
        }
        /* Convert to lower case */
        input_str[i] = tolower(input_str[i]);
        i++;
    }
}

int main() {
    /* Get user input */
    char input_str[100];
    printf("Enter a string: ");
    fgets(input_str, 100, stdin);

    /* Sanitize user input */
    sanitize_input(input_str);

    /* Print sanitized input */
    printf("Sanitized input: %s\n", input_str);
    return 0;
}