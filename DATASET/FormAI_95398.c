//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: curious
#include <stdio.h>
#include <ctype.h>
#define MAX_LENGTH 100

// Function to sanitize user input
void sanatize(char string[]) {
    int i = 0;
    while(string[i] != '\0') {
        // Convert to lowercase
        if(isupper(string[i])) {
            string[i] = tolower(string[i]);
        }
        // Remove non-alphabetic characters
        if(!isalpha(string[i])) {
            int j = i;
            while(string[j] != '\0') {
                string[j] = string[j+1];
                j++;
            }
        }
        i++;
    }
}

int main() {
    char userInput[MAX_LENGTH];
    printf("Enter some text to sanitize: ");
    fgets(userInput, MAX_LENGTH, stdin);

    // Sanitize user input
    sanatize(userInput);

    // Print sanitized user input
    printf("Sanitized input: %s", userInput);
    
    return 0;
}