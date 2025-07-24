//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: cheerful
#include<stdio.h>
#include<string.h>

//function to convert text to morse code
void textToMorse(char text){
    switch(text){
        case 'a':
            printf(".- ");
            break;
        case 'b':
            printf("-... ");
            break;
        case 'c':
            printf("-.-. ");
            break;
        case 'd':
            printf("-.. ");
            break;
        case 'e':
            printf(". ");
            break;
        case 'f':
            printf("..-. ");
            break;
        case 'g':
            printf("--. ");
            break;
        case 'h':
            printf(".... ");
            break;
        case 'i':
            printf(".. ");
            break;
        case 'j':
            printf(".--- ");
            break;
        case 'k':
            printf("-.- ");
            break;
        case 'l':
            printf(".-.. ");
            break;
        case 'm':
            printf("-- ");
            break;
        case 'n':
            printf("-. ");
            break;
        case 'o':
            printf("--- ");
            break;
        case 'p':
            printf(".--. ");
            break;
        case 'q':
            printf("--.- ");
            break;
        case 'r':
            printf(".-. ");
            break;
        case 's':
            printf("... ");
            break;
        case 't':
            printf("- ");
            break;
        case 'u':
            printf("..- ");
            break;
        case 'v':
            printf("...- ");
            break;
        case 'w':
            printf(".-- ");
            break;
        case 'x':
            printf("-..- ");
            break;
        case 'y':
            printf("-.-- ");
            break;
        case 'z':
            printf("--.. ");
            break;
        case ' ':
            printf("/ ");
            break;
        default:
            printf("# ");
            break;
    }
}

//driver function
int main(){
    char text[100];
    printf("Welcome to the cheerful Text to Morse Code Converter!\n");
    printf("Please enter the text you want to convert to Morse Code:\n");
    fgets(text, 100, stdin);
    printf("The Morse Code for your text is:\n");

    for(int i=0;i<strlen(text);i++){
        text[i] = tolower(text[i]);
        textToMorse(text[i]);
    }

    printf("\nThank you for using our program, have a Morse-tastic day!\n");
    return 0;
}