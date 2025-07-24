//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Morse code conversion function
void convertToMorse(char *message) {
    char *morseCode[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
                           "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
                           "-.--", "--.."};
    char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 
                      'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int n = strlen(message);
    for(int i=0; i<n; i++) {
        if(message[i] == ' ') {
            // Wait for 3 time units 
            printf("    ");
            continue;
        }
        if(message[i] >= 'a' && message[i] <= 'z') {
            // Convert lowercase letters to uppercase
            message[i] = message[i] - 32;
        }
        int index = message[i] - 'A';
        if(index < 0 || index > 25) {
            // Ignore non-alphabetic characters 
            continue;
        }
        printf("%s ", morseCode[index]);
    }
}

int main() {
    // Generate random message
    srand(time(NULL));
    char message[100];
    for(int i=0; i<10; i++) {
        message[i] = 'A' + rand() % 26;
    }
    message[10] = ' ';
    for(int i=11; i<20; i++) {
        message[i] = 'A' + rand() % 26;
    }
    message[20] = '\0';
    printf("Message: %s\n", message);
    
    // Convert message to Morse code
    convertToMorse(message);
    
    return 0;
}