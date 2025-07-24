//FormAI DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
    // The case of the missing vowels
    char message[] = "Ths sntnc hs mssng ll ts vwls!";
    char vowels[] = "aeiouAEIOU";
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < strlen(vowels); j++) {
            if (message[i] == vowels[j]) {
                message[i] = '_';
            }
        }
    }
    printf("The message is: %s\n", message);
    
    // The case of the secret message
    char text[] = "hbgb thw xhqz";
    int shift = 5;
    len = strlen(text);
    for (int i = 0; i < len; i++) {
        // Ignore spaces and other non-alphabetic characters
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
        }
        else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
        }
    }
    printf("The decoded message is: %s\n", text);
    
    return 0;
}