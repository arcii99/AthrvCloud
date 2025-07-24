//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int main() {
    char userInput[100];
    printf("Enter a string: ");
    fgets(userInput, 100, stdin);
    userInput[strcspn(userInput, "\n")] = 0; // remove newline character
    
    char sanitizedInput[100];
    int index = 0;
    for (int i = 0; i < strlen(userInput); i++) {
        if (userInput[i] >= 'a' && userInput[i] <= 'z') { // only allow lowercase letters
            sanitizedInput[index] = userInput[i];
            index++;
        }
    }
    sanitizedInput[index] = '\0';
    
    printf("Your sanitized input: %s", sanitizedInput);
    return 0;
}