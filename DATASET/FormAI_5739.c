//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include<stdio.h>
#include<string.h>

void translate(char* message);

int main()
{
    char message[100];
    printf("Enter a message in the Alien Language: ");
    fgets(message, sizeof(message), stdin);
    translate(message);
    return 0;
}

void translate(char* message)
{
    int i,n;
    n=strlen(message);
    printf("Translation of message: ");
    for(i=0;i<n;i++)
    {
        switch(message[i])
        {
            case '@':
                printf("A");
                break;
            case '6':
                printf("B");
                break;
            case '(':
                printf("C");
                break;
            case '|)':
                printf("D");
                break;
            case '3':
                printf("E");
                break;
            case '|=':
                printf("F");
                break;
            case '9':
                printf("G");
                break;
            case ')((':
                printf("H");
                break;          
            case '|' :
                printf("I");
                break;
            case '_|':
                printf("J");
                break;
            case '|<':
                printf("K");
                break;
            case '1':
                printf("L");
                break;
            case '|\\/|':
                printf("M");
                break;
            case '|\\|':
                printf("N");
                break;
            case '0':
                printf("O");
                break;
            case '|_':
                printf("P");
                break;
            case '()_':
                printf("Q");
                break;          
            case '|_\\_':
                printf("R");
                break;
            case '5':
                printf("S");
                break;
            case '7':
                printf("T");
                break;
            case '|_|':
                printf("U");
                break;
            case '\\/':
                printf("V");
                break;
            case '\\/\\/':
                printf("W");
                break;
            case '><':
                printf("X");
                break;
            case '`/':
                printf("Y");
                break;
            case '2':
                printf("Z");
                break;          
            default:
                printf("%c",message[i]);
        }
    }
    printf("\n");
}