//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the morse code array
const char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/", " "};

// define the alphabet array
const char *alphabet[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " ", "\n"};

// function to convert text to morse code
void text_to_morse(char *input_text){
    int i = 0, j = 0, k = 0;
    char *output_morse = (char *)malloc(strlen(input_text) * 10);  // allocate memory for the output
    
    // loop through each character of the input text
    while(input_text[i]){
        
        // loop through each character of the alphabet to find a match
        for(j=0; j<27; j++){
            
            // if a match is found, append the morse code equivalent to the output string
            if(*input_text == *alphabet[j]){
                strcat(output_morse, morse_code[j]);
                strcat(output_morse, " ");
            }
        }
        input_text++;
    }
    printf("Morse code representation of the text: %s \n", output_morse);
    free(output_morse);  // free the memory allocated for the output string
}

int main(){
    char input_text[100];
    printf("Enter text to be converted to morse code: ");
    fgets(input_text, 100, stdin);  // read input from user
    
    printf("Input text: %s", input_text);
    text_to_morse(input_text);  // call the function to convert to morse code
    
    return 0;
}