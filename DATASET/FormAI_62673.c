//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* textToMorse(char* input){
    
    //Morse code array
    char* morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/", " "};
    char* alpha[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " ", " "};   
    
    char* output = malloc(sizeof(char) * strlen(input) * 5); //Allocating memory to output string
    
    for(int i=0; i<strlen(input); i++){
        for(int j=0; j<27; j++){
            if(toupper(input[i]) == alpha[j][0]){
                strcat(output, morse[j]); 
                strcat(output, " ");
                break;
            }
        }
    } 
    return output;
}

int main(){
    printf("****************************************\n");
    printf("********** WELCOME TO MORSE CODE ********\n");
    printf("********** TEXT TO MORSE CONVERTER ******\n");
    printf("****************************************\n");
    
    char input[100];
    printf("Enter the text to convert to Morse code: ");
    scanf("%[^\n]", input); //Reading input with spaces
    
    char* output = textToMorse(input); //Calling conversion function
    
    printf("****************************************\n");
    printf("Morse code for %s is:\n%s", input, output);
    printf("****************************************\n");
    
    free(output); //Freeing allocated memory
    
    return 0;
}