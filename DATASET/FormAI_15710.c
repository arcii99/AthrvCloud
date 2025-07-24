//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: surprised
#include <stdio.h>
#include <string.h>

void printMorse(char c);

int main()
{
    char input[100];
    
    printf("Enter text to convert to Morse code: ");
    scanf("%[^\n]", input);
    
    printf("\nYour text in Morse code:\n");
    
    for (int i = 0; i < strlen(input); i++)
    {
        printMorse(input[i]);
        printf(" ");
    }
    
    printf("\n");
    
    return 0;
}

void printMorse(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        c += 32; 
    }
    
    switch (c)
    {
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
        case '0':
            printf("-----");
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
        default:
            printf(" ");
            break;
    }
}