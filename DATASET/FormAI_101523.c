//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: synchronous
#include <stdio.h>
#include <string.h>

char* morsecode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
                     "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
                     "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

char* alphabets = "abcdefghijklmnopqrstuvwxyz0123456789";

char* encode(char* text) {    // function to convert text to morse code
    int len = strlen(text);   
    char* result = (char*) malloc(4*len);   // allocating memory for result string
  
    for(int i=0; i<len; i++) {
        char c = tolower(text[i]);  // converting uppercase letters to lowercase
        int idx = strchr(alphabets, c) - alphabets; // finding index of the character in alphabets array
        if(idx >=0 && idx<=35) {
            strcat(result, morsecode[idx]);  // concatenating morse code of the character to result string
        }
        else {
            strcat(result, "");  // skipping non-alphanumeric characters
        }
        strcat(result, " ");    // adding space between morse code of each characters
    }
    return result;
}

int main() {
    char text[100];
    printf("Enter text to convert to morse code: ");
    fgets(text, 100, stdin);   // reading input string from user
    
    char* morse = encode(text);  // calling encode function
    
    printf("Morse Code: %s", morse);
    
    free(morse);   // deallocating memory
    return 0;
}