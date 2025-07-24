//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: irregular
#include<stdio.h>
#include<string.h>

//Function to convert text to morse code
void convertToMorse(char character){
    if(character == 'a' || character == 'A'){
        printf(".- ");
    }
    else if(character == 'b' || character == 'B'){
        printf("-... ");
    }
    else if(character == 'c' || character == 'C'){
        printf("-.-. ");
    }
    else if(character == 'd' || character == 'D'){
        printf("-.. ");
    }
    else if(character == 'e' || character == 'E'){
        printf(". ");
    }
    else if(character == 'f' || character == 'F'){
        printf("..-. ");
    }
    else if(character == 'g' || character == 'G'){
        printf("--. ");
    }
    else if(character == 'h' || character == 'H'){
        printf(".... ");
    }
    else if(character == 'i' || character == 'I'){
        printf(".. ");
    }
    else if(character == 'j' || character == 'J'){
        printf(".--- ");
    }
    else if(character == 'k' || character == 'K'){
        printf("-.- ");
    }
    else if(character == 'l' || character == 'L'){
        printf(".-.. ");
    }
    else if(character == 'm' || character == 'M'){
        printf("-- ");
    }
    else if(character == 'n' || character == 'N'){
        printf("-. ");
    }
    else if(character == 'o' || character == 'O'){
        printf("--- ");
    }
    else if(character == 'p' || character == 'P'){
        printf(".--. ");
    }
    else if(character == 'q' || character == 'Q'){
        printf("--.- ");
    }
    else if(character == 'r' || character == 'R'){
        printf(".-. ");
    }
    else if(character == 's' || character == 'S'){
        printf("... ");
    }
    else if(character == 't' || character == 'T'){
        printf("- ");
    }
    else if(character == 'u' || character == 'U'){
        printf("..- ");
    }
    else if(character == 'v' || character == 'V'){
        printf("...- ");
    }
    else if(character == 'w' || character == 'W'){
        printf(".-- ");
    }
    else if(character == 'x' || character == 'X'){
        printf("-..- ");
    }
    else if(character == 'y' || character == 'Y'){
        printf("-.-- ");
    }
    else if(character == 'z' || character == 'Z'){
        printf("--.. ");
    }
    else if(character == ' '){
        printf("/ ");
    }
}

int main(){
    char text[100];
    printf("Enter text to convert to morse code: ");
    fgets(text, 100, stdin);
    printf("Morse code of the entered text is: ");
    for(int i=0; i<strlen(text); i++){
        convertToMorse(text[i]);
    }
    return 0;
}