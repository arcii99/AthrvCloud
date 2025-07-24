//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitizeInput(char* inputString){
    // Removes leading and trailing white space
    char* trimmedString = strtok(inputString, " \t\n\r");
    char* sanitizedString = strdup(trimmedString);
    int len = strlen(trimmedString);
    int i, j = 0;

    for(i = 0; i < len; i++){
        if(trimmedString[i] >= '0' && trimmedString[i] <= '9'){
            sanitizedString[j++] = trimmedString[i];
        }
        else if(trimmedString[i] >= 'A' && trimmedString[i] <= 'Z'){
            sanitizedString[j++] = trimmedString[i] + 32;
        }
        else if(trimmedString[i] >= 'a' && trimmedString[i] <= 'z'){
            sanitizedString[j++] = trimmedString[i];
        }
    }

    sanitizedString[j] = '\0';
    strcpy(inputString, sanitizedString);
    free(sanitizedString);
}

int main(void){
    char input[100];
    printf("Enter a sentence less than 100 characters:\n");
    fgets(input, 100, stdin);
    sanitizeInput(input);
    printf("Sanitized input: %s\n", input);
    return 0;
}