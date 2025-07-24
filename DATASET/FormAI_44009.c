//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include <stdio.h>

//This program is a C alien language translator
//It will translate any text typed by the user into the C alien language

int main()
{
    char text[1000]; //User input text will be stored here
    int textLength; //Length of the input text
    

    //Greeting the user
    printf("Welcome to the C Alien Language Translator program!\n\n");
    printf("This program will translate any text you type into the C Alien Language.\n\n");

    //Getting user input
    printf("Please enter the text you want to translate: ");
    fgets(text, 1000, stdin);
    textLength = strlen(text);

    //Translating user input
    printf("\n\nTranslation into the C Alien Language: \n");

    for(int i=0;i<textLength;i++)
    {
        switch(text[i])
        {
            case 'a':
                printf("al");
                break;

            case 'b':
                printf("be");
                break;

            case 'c':
                printf("cry");
                break;

            case 'd':
                printf("do");
                break;

            case 'e':
                printf("es");
                break;

            case 'f':
                printf("fry");
                break;

            case 'g':
                printf("gy");
                break;

            case 'h':
                printf("hie");
                break;

            case 'i':
                printf("ice");
                break;

            case 'j':
                printf("jy");
                break;

            case 'k':
                printf("ke");
                break;

            case 'l':
                printf("lee");
                break;

            case 'm':
                printf("my");
                break;

            case 'n':
                printf("ny");
                break;

            case 'o':
                printf("oz");
                break;

            case 'p':
                printf("py");
                break;

            case 'q':
                printf("qy");
                break;

            case 'r':
                printf("ry");
                break;

            case 's':
                printf("sy");
                break;

            case 't':
                printf("ty");
                break;

            case 'u':
                printf("uz");
                break;

            case 'v':
                printf("vy");
                break;

            case 'w':
                printf("we");
                break;

            case 'x':
                printf("xy");
                break;

            case 'y':
                printf("yie");
                break;

            case 'z':
                printf("zy");
                break;

            case ' ':
                printf(" ");
                break;

            default:
                printf("%c", text[i]); 
        }
    }

    printf("\n\nThank you for using the C Alien Language Translator program!\n");
    printf("We hope you found it useful.\n\n");

    return 0;
}