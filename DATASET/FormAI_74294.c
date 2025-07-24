//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: immersive
#include <stdio.h>
#include <string.h>

// Declare global array for alien language and its translation
char alien[] = {'&','^','%','@','*','(','$','#','!','+'};
char translation[] = {'a','e','i','o','u','y','s','t','n','r'};

// Declare function for translating alien language
void translate(char* input) {
    int length = strlen(input);
    char output[length+1]; // Create a blank output string with same length as input
    
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < 10; j++) {
            if (input[i] == alien[j]) { // If character in input matches alien language character
                output[i] = translation[j]; // Add corresponding translated character to output string
                break; // Exit inner loop and move on to next character in input
            }
            else if (j == 9) { // If current character in input doesn't match any alien language character
                output[i] = input[i]; // Leave it as is in output
            }
        }
    }
    output[length] = '\0'; // Terminate output string with null character
    printf("Translated: %s\n", output); // Print translated input
}

int main() {
    char input[100]; // Declare string to store user input
    printf("Enter a string to be translated in alien language:\n");
    scanf("%[^\n]%*c", input); // Accept input with spaces
    
    printf("Original: %s\n", input); // Print original input
    translate(input); // Call translate function with user input
    
    return 0; // End program
}