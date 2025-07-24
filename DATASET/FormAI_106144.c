//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>

int main() {
    char str[50], sanitized_str[50], c;
    int i = 0, j = 0;

    printf("Enter a string: ");

    while((c = getchar()) != '\n') {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ') {
            str[i++] = c;
        }
    }

    str[i] = '\0';

    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' ') {
            if(str[i+1] != ' ' && str[i+1] != '\0') {
                sanitized_str[j++] = str[i];
            }
        }
        else if(str[i] >= '0' && str[i] <= '9') {
            sanitized_str[j++] = str[i];
        }
        else if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            sanitized_str[j++] = tolower(str[i]);
        }
    }

    sanitized_str[j] = '\0';

    printf("\nSanitized string: %s", sanitized_str);

    return 0;
}