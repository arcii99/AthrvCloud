//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include<stdio.h>
#include<string.h>

void morse(char c)
{
    //conversion of characters to Morse code
    switch(c)
    {
        case 'a':
        case 'A':
            printf(".- ");
            break;
        case 'b':
        case 'B':
            printf("-... ");
            break;
        case 'c':
        case 'C':
            printf("-.-. ");
            break;
        case 'd':
        case 'D':
            printf("-.. ");
            break;
        case 'e':
        case 'E':
            printf(". ");
            break;
        case 'f':
        case 'F':
            printf("..-. ");
            break;
        case 'g':
        case 'G':
            printf("--. ");
            break;
        case 'h':
        case 'H':
            printf(".... ");
            break;
        case 'i':
        case 'I':
            printf(".. ");
            break;
        case 'j':
        case 'J':
            printf(".--- ");
            break;
        case 'k':
        case 'K':
            printf("-.- ");
            break;
        case 'l':
        case 'L':
            printf(".-.. ");
            break;
        case 'm':
        case 'M':
            printf("-- ");
            break;
        case 'n':
        case 'N':
            printf("-. ");
            break;
        case 'o':
        case 'O':
            printf("--- ");
            break;
        case 'p':
        case 'P':
            printf(".--. ");
            break;
        case 'q':
        case 'Q':
            printf("--.- ");
            break;
        case 'r':
        case 'R':
            printf(".-. ");
            break;
        case 's':
        case 'S':
            printf("... ");
            break;
        case 't':
        case 'T':
            printf("- ");
            break;
        case 'u':
        case 'U':
            printf("..- ");
            break;
        case 'v':
        case 'V':
            printf("...- ");
            break;
        case 'w':
        case 'W':
            printf(".-- ");
            break;
        case 'x':
        case 'X':
            printf("-..- ");
            break;
        case 'y':
        case 'Y':
            printf("-.-- ");
            break;
        case 'z':
        case 'Z':
            printf("--.. ");
            break;
        case '1':
            printf(".---- ");
            break;
        case '2':
            printf("..--- ");
            break;
        case '3':
            printf("...-- ");
            break;
        case '4':
            printf("....- ");
            break;
        case '5':
            printf("..... ");
            break;
        case '6':
            printf("-.... ");
            break;
        case '7':
            printf("--... ");
            break;
        case '8':
            printf("---.. ");
            break;
        case '9':
            printf("----. ");
            break;
        case '0':
            printf("----- ");
            break;
        case ' ':
            printf("/ ");
            break;
        default:
            printf("\nInvalid character entered.\n");
    }
}

int main()
{
    char str[100];  //Input string
    int i, j, len;  //Loop variables and string length
    printf("Enter a string to convert to Morse code (Max length 100 characters): ");
    fgets(str, 100, stdin);  //Input string with fgets function
    
    len = strlen(str);  //Finding string length using strlen function
    
    printf("\nMorse code representation of the input string: \n");
    
    for(i=0; i<len; i++)  //Looping through each character of the input string
    {
        morse(str[i]);  //Converting the character to Morse code
        
        if(str[i]==' ')  //Adding a delay of 1 second after each word
            printf("\n");
        else
            printf(" ");
    }
    printf("\n");
    return 0;
}