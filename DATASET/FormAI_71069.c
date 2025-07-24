//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: sophisticated
#include <stdio.h>
#include <string.h>

/*
 * Function to convert a single character to morse code
 */
void morse(char c){
    switch(c) {
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
            printf("");
    }
}

/*
 * Function to convert a text string to morse code
 */
void textToMorse(char* str, int len) {
    int i;

    for(i=0;i<len;i++) {
        morse(str[i]);

        if(i+1 < len && str[i+1] != ' ') {
            printf(" ");
        }
    }
}

int main() {
    char text[1000];

    printf("Enter text to convert to morse code: ");
    fgets(text, 1000, stdin);
    text[strcspn(text, "\n")] = 0;

    textToMorse(text, strlen(text));

    return 0;
}