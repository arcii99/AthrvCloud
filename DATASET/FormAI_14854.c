//FormAI DATASET v1.0 Category: String manipulation ; Style: real-life
#include <stdio.h>
#include <string.h>

int main() {
    // Get the input string from the user
    char inputStr[100];
    printf("Enter a string: ");
    scanf("%s", inputStr);
    
    // Capitalize the first letter of every word in the string
    int i;
    int len = strlen(inputStr);
    int flag = 1;   // Flag to indicate when to capitalize
    for (i = 0; i < len; i++) {
        if (flag == 1 && inputStr[i] != ' ') {
            if (inputStr[i] >= 'a' && inputStr[i] <= 'z') {
                inputStr[i] -= 32;  // Convert to uppercase
            }
            flag = 0;
        } else if (inputStr[i] == ' ') {
            flag = 1;
        }
    }
    
    // Reverse the order of the words in the string
    char reversedStr[100];
    char *word = strtok(inputStr, " ");
    while (word != NULL) {
        strcat(reversedStr, word);
        strcat(reversedStr, " ");
        word = strtok(NULL, " ");
    }
    int newLen = strlen(reversedStr);
    reversedStr[newLen - 1] = '\0';   // Replace last space with null terminator
    
    // Print the output string
    printf("Output string: %s\n", reversedStr);
    
    return 0;
}