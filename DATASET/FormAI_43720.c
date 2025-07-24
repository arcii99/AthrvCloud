//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: mathematical
#include <stdio.h>
#include <string.h>

void convertToMorse(char character);

int main(){
    char message[100];
    printf("Enter a message to convert to Morse code: ");
    fgets(message, 100, stdin);

    int i;
    for(i = 0; i < strlen(message); i++){
        if(message[i] == ' '){
            printf("  "); //two spaces indicate a space between words
        }
        else{
            convertToMorse(message[i]);
            printf(" "); //one space indicates a space between characters
        }
    }

    return 0;
}

void convertToMorse(char character){
    switch (character) {
        case 'a':
            printf(".-");
            break;
        case 'b':
            printf("-...");
            break;
        case 'c':
            printf("-.-.");
            break;
        case 'd':
            printf("-..");
            break;
        case 'e':
            printf(".");
            break;
        case 'f':
            printf("..-.");
            break;
        case 'g':
            printf("--.");
            break;
        case 'h':
            printf("....");
            break;
        case 'i':
            printf("..");
            break;
        case 'j':
            printf(".---");
            break;
        case 'k':
            printf("-.-");
            break;
        case 'l':
            printf(".-..");
            break;
        case 'm':
            printf("--");
            break;
        case 'n':
            printf("-.");
            break;
        case 'o':
            printf("---");
            break;
        case 'p':
            printf(".--.");
            break;
        case 'q':
            printf("--.-");
            break;
        case 'r':
            printf(".-.");
            break;
        case 's':
            printf("...");
            break;
        case 't':
            printf("-");
            break;
        case 'u':
            printf("..-");
            break;
        case 'v':
            printf("...-");
            break;
        case 'w':
            printf(".--");
            break;
        case 'x':
            printf("-..-");
            break;
        case 'y':
            printf("-.--");
            break;
        case 'z':
            printf("--..");
            break;
        case '1':
            printf(".----");
            break;
        case '2':
            printf("..---");
            break;
        case '3':
            printf("...--");
            break;
        case '4':
            printf("....-");
            break;
        case '5':
            printf(".....");
            break;
        case '6':
            printf("-....");
            break;
        case '7':
            printf("--...");
            break;
        case '8':
            printf("---..");
            break;
        case '9':
            printf("----.");
            break;
        case '0':
            printf("-----");
            break;
        default:
            printf(""); //if character is not a letter or number, ignore it
    }
}