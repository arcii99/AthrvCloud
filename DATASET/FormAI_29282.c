//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: modular
#include <stdio.h>
#include <string.h>

//Function declarations
void separator(void);
void printMorse(char letter);
void convertToMorse(char message[]);
void printMorseCode(char letter);
void convertWordToMorse(char word[]);
void convertSentenceToMorse(char sentence[]);

//Main function
int main(void)
{
    char message[100];
    printf("Please enter the text to be converted to Morse code: ");
    fgets(message, 100, stdin);
    convertToMorse(message);
    separator();
    return 0;
}

//Separator function
void separator(void)
{
    printf("\n------------------------------------------------\n\n");
}

//Print function
void printMorse(char letter)
{
    printf("%c ", letter);
}

//Convert to Morse function
void convertToMorse(char message[])
{
    char sentence[50][50];
    char *word;
    int i = 0;

    //Dividing the message into words
    word = strtok(message, " ");
    while (word != NULL)
    {
        strcpy(sentence[i], word);
        i++;
        word = strtok(NULL, " ");
    }

    //Converting each word into Morse code
    for (int j = 0; j < i; j++)
    {
        convertWordToMorse(sentence[j]);
    }
}

//Print Morse code function
void printMorseCode(char letter)
{
    switch (letter)
    {
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
    case '0':
        printf("----- ");
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
    case ' ':
        printf("/ ");
        break;
    default:
        break;
    }
}

//Convert Word to Morse function
void convertWordToMorse(char word[])
{
    int length = strlen(word);

    //Converting each letter to Morse code
    for (int i = 0; i < length - 1; i++)
    {
        printMorseCode(word[i]);
    }
    printMorseCode(word[length - 1]);
    printf("  ");
}