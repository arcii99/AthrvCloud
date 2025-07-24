//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Morse code string representation for each alphabet
const char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
                            ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", 
                            ".--", "-..-", "-.--", "--..", "/", ""};

// Function to convert a single character to its Morse code equivalent
char* char_to_morse_code(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse_code[c - 'A'];
    }
    else if (c >= 'a' && c <= 'z') {
        return morse_code[c - 'a'];
    }
    else if (c >= '0' && c <= '9') {
        return morse_code[c - '0' + 26];
    }
    else if (c == ' ') {
        return morse_code[27];
    }
    else {
        return "";
    }
}

// Function to convert a text string to its Morse code equivalent
void* text_to_morse_code(void* args) {
    char* text = (char*) args;
    int text_len = strlen(text);
    
    // Allocate memory to store the Morse code string
    char* morse_code_str = (char*)malloc(sizeof(char) * text_len * 5);
    
    // Convert each character to its Morse code equivalent
    for (int i = 0; i < text_len; i++) {
        char* morse_code_char = char_to_morse_code(text[i]);
        strcat(morse_code_str, morse_code_char);
        strcat(morse_code_str, " ");
    }
    
    printf("Text: %s\nMorse Code: %s\n", text, morse_code_str);
    
    free(morse_code_str);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    char text1[] = "Hello World";
    char text2[] = "Programming is fun!";
    
    // Create two threads to convert two different text strings to Morse code
    pthread_create(&thread1, NULL, text_to_morse_code, (void*) text1);
    pthread_create(&thread2, NULL, text_to_morse_code, (void*) text2);
    
    // Wait for the threads to finish before exiting the program
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    return 0;
}