//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

// Define Morse code equivalents for each character as an array of strings
const char* morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", // J-R 
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", // S-Z
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." // 0-9
};

// Function to convert a string to Morse code
void* text_to_morse(void* arg) {
    char* text = (char*)arg;
    int len = strlen(text);
    for(int i=0; i<len; i++) {
        // Convert each character to uppercase and get its Morse code equivalent
        char c = toupper(text[i]);
        const char* morse = (c >= 'A' && c <= 'Z') ? morse_code[c - 'A'] :
            (c >= '0' && c <= '9') ? morse_code[c - '0' + 26] : "";
        // Print the Morse code equivalent of the character
        printf("%s ", morse);
    }
    printf("\n");
    pthread_exit(NULL);
}

// Main function to get user input and start threads
int main() {
    char text[100];
    printf("Enter text to convert to Morse code: ");
    fgets(text, 100, stdin);
    // Remove newline character at the end of input
    text[strcspn(text, "\n")] = 0;
    // Split the input into words using strtok
    char* word = strtok(text, " ");
    // Create a thread for each word
    pthread_t thread;
    while(word != NULL) {
        pthread_create(&thread, NULL, text_to_morse, (void*)word);
        word = strtok(NULL, " ");
    }
    // Wait for all threads to complete
    pthread_join(thread, NULL);
    return 0;
}