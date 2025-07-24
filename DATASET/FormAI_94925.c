//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: peaceful
#include <stdio.h>
#include <string.h>

char *morse[] = {   // Morse code array for each letter
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."    
};

char *text_to_morse(char text[]) {  // function to convert text to Morse code
    int len = strlen(text);
    char *result = "";
    for(int i=0; i<len; i++) {
        if (text[i] == ' ') {
            result = strcat(result, "   ");  // Add 3 spaces for word separator
        } else if (text[i]>='A'&&text[i]<='Z') {
            result = strcat(result, morse[text[i]-'A']);  // Convert capital letter to Morse code
            result = strcat(result, " ");
        } else if (text[i]>='a'&&text[i]<='z') {
            result = strcat(result, morse[text[i]-'a']);  // Convert lower letter to Morse code
            result = strcat(result, " ");
        }
    }
    return result;
}

int main() {
    char text[100];
    printf("Enter a text to convert to Morse code: ");
    fgets(text, sizeof(text), stdin); // Read input text from user
    char *result = text_to_morse(text);  // Convert input text to Morse code
    printf("The Morse code for \"%s\" is:\n%s", text, result);  // Print the Morse code result
    return 0;
}