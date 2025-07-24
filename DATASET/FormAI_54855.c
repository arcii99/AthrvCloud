//FormAI DATASET v1.0 Category: String manipulation ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len, count = 0;

    printf("Enter a string: ");
    fgets(str, 100, stdin);
    
    len = strlen(str);

    for(i = 0; i < len; i++) {
        if(str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    char new_str[100];

    printf("Original string: %s\n", str);

    for(i = len - 1; i >= 0; i--) {
        new_str[count++] = str[i];
    }

    new_str[count] = '\0';

    printf("Reversed string: %s\n", new_str);

    char substr[50];

    printf("Enter a substring: ");
    scanf("%s", substr);

    char *result = strstr(str, substr);

    if(result) {
        printf("'%s' is found in '%s' at position %d.\n", substr, str, result - str);
    } else {
        printf("'%s' is not found in '%s'.\n", substr, str);
    }

    return 0;
}