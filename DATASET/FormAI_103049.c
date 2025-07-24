//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: unmistakable
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void sanitizeInput(char *input){
    int i = 0;

    // Remove leading white space
    while (isspace(input[i]))
        i++;

    // Remove trailing white space
    int end = strlen(input) - 1;
    while (end >= 0 && isspace(input[end]))
        end--;
    input[end + 1] = '\0';

    // Remove non-alphanumeric characters
    int j = 0;
    for (i = 0; input[i]; i++){
        if (isalnum(input[i])){
            input[j++] = input[i];
        }
    }
    input[j] = '\0';

    // Convert to lowercase
    for (i = 0; input[i]; i++)
        input[i] = tolower(input[i]);
}

int main(){
    char input[100];

    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin);

    sanitizeInput(input);

    printf("Sanitized input: %s\n", input);

    return 0;
}