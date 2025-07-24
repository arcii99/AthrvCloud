//FormAI DATASET v1.0 Category: Text processing ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    char output[100];
    
    printf("Enter a sentence: ");
    scanf("%[^\n]s", input); // Read input until \n is encountered
    
    // Loop through each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        if ((input[i] >= 65 && input[i] <= 77) || (input[i] >= 97 && input[i] <= 109)) {
            // Shift the character forward by 13 positions
            output[i] = input[i] + 13;
        }
        else if ((input[i] >= 78 && input[i] <= 90) || (input[i] >= 110 && input[i] <= 122)) {
            // Shift the character backward by 13 positions
            output[i] = input[i] - 13;
        }
        else {
            // Copy the character as is
            output[i] = input[i];
        }
    }
    
    printf("Original sentence: %s\n", input);
    printf("Futuristic sentence: %s\n", output);
    
    return 0;
}