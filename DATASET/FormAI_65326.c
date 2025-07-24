//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multivariable
#include<stdio.h>
#include<string.h>

char* textToMorse(char c);

int main(){
    char input[100];
    printf("Enter the text to be converted to Morse Code: ");
    gets(input);

    int length = strlen(input);
    char output[500];

    for(int i=0; i<length; i++){
        if(input[i]==' '){
            strcat(output,"   ");
        }
        else{
            strcat(output, textToMorse(input[i]));
            strcat(output," ");
        }
    }

    printf("Morse Code output: %s", output);
    return 0;
}

char* textToMorse(char c){
    char *morse[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
                    "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    char* output = "";
    if(c >= 'A' && c <= 'Z'){
        output = morse[c-'A'];
    }
    else if(c >= 'a' && c <= 'z'){
        output = morse[c-'a'];
    }
    else{
        output=" ";
    }
    return output;
}