//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void sanitize(char *input) {
    int i, j = 0;
    char temp[1000];
    for(i = 0; input[i] != '\0'; i++) {
        if(input[i] == ' ')
            continue;
        if(input[i] == '&' || input[i] == '#')
            break;
        if(isalnum(input[i]))
            temp[j++] = input[i];
        else if(input[i] == '.' || input[i] == '/')
            temp[j++] = input[i];
    }
    temp[j] = '\0';
    strcpy(input, temp);
}

int main() {
    printf("Enter a URL: ");
    char input[1000];
    fgets(input, 1000, stdin);
    sanitize(input);
    printf("Sanitized URL: %s\n", input);
    return 0;
}