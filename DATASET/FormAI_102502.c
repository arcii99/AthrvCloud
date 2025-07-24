//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    char sanitized[1000];
    printf("Enter a string to be sanitized: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character
    int j = 0;
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') { // convert uppercase letters to lowercase
            sanitized[j] = input[i] + 32;
            j++;
        } else if(input[i] >= 'a' && input[i] <= 'z' || input[i] == ' ' || input[i] == '-') { // keep lowercase letters, spaces, and hyphens
            sanitized[j] = input[i];
            j++;
        } else { // remove all other characters
            continue;
        }
    }
    sanitized[j] = '\0'; // add null terminator to sanitized string
    printf("Sanitized string: %s\n", sanitized);

    return 0;
}