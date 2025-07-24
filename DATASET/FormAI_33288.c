//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: complete
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    //Define the morse code equivalences of each character
    char *alphabet[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                          ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                          "...","-","..-","...-",".--","-..-","-.--","--.."};
    //Define the characters that the program can handle
    char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890,.?;!()\"\'";
    //Get the user input
    printf("Enter the text to be converted to Morse code:\n");
    char input_text[1000];
    fgets(input_text, 1000, stdin);
    //Get the length of the input text
    int input_length = strlen(input_text);
    //Convert each character to its Morse code equivalent
    for(int i=0; i<input_length; i++){
        char c = input_text[i];
        //Check if the input character is allowed
        if(strchr(allowed_chars, c) == NULL){
            printf("%c is not a valid character and will be skipped\n", c);
        } else {
            //Convert the character to lowercase
            if(c >= 'A' && c <= 'Z'){
                c += 32;
            }
            //Print the Morse code equivalent
            if(c == ' '){
                printf(" ");
            } else {
                printf("%s ", alphabet[c - 'a']);
            }
        }
    }
    printf("\n");
    return 0;
}