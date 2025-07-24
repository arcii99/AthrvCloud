//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    printf("Enter a string: ");
    char input[50];
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0'; //removes trailing newline

    char sanitized[50] = {'\0'};
    int sanitize_index = 0;

    for(int i = 0; i < strlen(input); i++){
        if(isalnum(input[i])){
            sanitized[sanitize_index++] = input[i];
        }
    }
    printf("----------------------\n");
    printf("Sanitized String: %s\n", sanitized);
    printf("----------------------\n");

    return 0;
}