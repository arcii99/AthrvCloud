//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: cheerful
#include <stdio.h>
#include <string.h>

// Function to convert text to morse code
void textToMorse(const char* text)
{
    // Arrays to hold morse code characters and corresponding text characters
    char morseChar[38][10] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", ".-.-.-", "--..--", "..--.."};
    char textChar[38] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.', ',', '?'};
    
    int i, j;
    
    // Loop through input text
    for (i = 0; i < strlen(text); i++) {
        // Match current character with corresponding morse code character
        for (j = 0; j < 38; j++) {
            if (text[i] == textChar[j]) {
                printf("%s ", morseChar[j]);
                break;
            }
        }
    }
    printf("\n");
}

int main()
{
    // Greeting message
    printf("Hello! I can convert your text to Morse code. Let's get started!\n\n");

    // Loop to ask user for input text and convert it to morse code
    while (1) {
        char input[100];
        printf("Enter your text (type 'exit' to quit): ");
        scanf("%s", input);
        
        // Check if user wants to exit
        if (strcmp(input, "exit") == 0) {
            printf("\nThank you for using my service. Goodbye!\n");
            break;
        }
        
        // Convert user input to morse code and print
        textToMorse(input);
    }

    return 0;
}