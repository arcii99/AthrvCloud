//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main(void) {
    char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", 
                          "--.", "....", "..", ".---", "-.-", ".-..",
                          "--", "-.", "---", ".--.", "--.-", ".-.", 
                          "...", "-", "..-", "...-", ".--", "-..-", 
                          "-.--", "--..", "/", "\0"};
    // Morse code for A to Z and space, followed by end of string and null terminator.
                          
    char input[100];
    printf("Enter the string to be converted to Morse code: ");
    scanf("%[^\n]",input); // Take input string with spaces using %[^\n]
    
    int len = strlen(input);
    for(int i=0;i<len;i++) {
        if(input[i] == ' ') {
            printf("/ "); // Print a slash for space
        } else if(input[i] >= 'a' && input[i] <= 'z') {
            printf("%s ",morse_code[input[i] - 'a']); // Print Morse code for lowercase letters
        } else if(input[i] >= 'A' && input[i] <= 'Z') {
            printf("%s ",morse_code[input[i] - 'A']); // Print Morse code for uppercase letters
        }
    }
    printf("\n");
    return 0; // Return success code
}