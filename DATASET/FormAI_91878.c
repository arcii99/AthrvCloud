//FormAI DATASET v1.0 Category: Text processing ; Style: brave
#include <stdio.h>
#include <string.h>

void process_text(char* text) {
    char buffer[1024]; // We'll use a buffer to hold the processed text
    
    // Let's start by removing any vowels from the text
    int i, j;
    for (i = 0, j = 0; text[i] != '\0'; i++) {
        if (text[i] != 'a' && text[i] != 'e' && text[i] != 'i' && text[i] != 'o' && text[i] != 'u' &&
            text[i] != 'A' && text[i] != 'E' && text[i] != 'I' && text[i] != 'O' && text[i] != 'U') {
            buffer[j++] = text[i]; // Copy the non-vowels into the buffer
        }
    }
    buffer[j] = '\0'; // Terminate the buffer with a null character
    
    // Now let's reverse the processed text
    int len = strlen(buffer);
    for (i = 0; i < len / 2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[len - i - 1];
        buffer[len - i - 1] = temp;
    }
    
    // Finally, let's convert the processed text to uppercase
    for (i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] >= 'a' && buffer[i] <= 'z') {
            buffer[i] = buffer[i] - 'a' + 'A';
        }
    }
    
    printf("%s\n", buffer);
}

int main() {
    char text[1024];
    printf("Enter some text: ");
    scanf("%[^\n]", text); // Read in a line of text (ignoring whitespace)
    
    process_text(text);
    
    return 0;
}