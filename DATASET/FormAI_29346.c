//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Cryptic
#include <stdio.h>

int main()
{
    char alien_msg[100], translated_msg[100]; //max length of message is 100 characters.

    printf("Enter the alien message to be translated: ");
    gets(alien_msg);

    for(int i=0; alien_msg[i]!='\0'; i++)
    {
        switch(alien_msg[i])
        {
            case 'A': translated_msg[i] = 'Z'; //reversing the alphabets
                      break;
            case 'B': translated_msg[i] = 'Y';
                      break;
            case 'C': translated_msg[i] = 'X';
                      break;
            case 'D': translated_msg[i] = 'W';
                      break;
            case 'E': translated_msg[i] = 'V';
                      break;
            case 'F': translated_msg[i] = 'U';
                      break;
            case 'G': translated_msg[i] = 'T';
                      break;
            case 'H': translated_msg[i] = 'S';
                      break;
            case 'I': translated_msg[i] = 'R';
                      break;
            case 'J': translated_msg[i] = 'Q';
                      break;
            case 'K': translated_msg[i] = 'P';
                      break;
            case 'L': translated_msg[i] = 'O';
                      break;
            case 'M': translated_msg[i] = 'N';
                      break;
            case 'N': translated_msg[i] = 'M'; 
                      break;
            case 'O': translated_msg[i] = 'L';
                      break;
            case 'P': translated_msg[i] = 'K';
                      break;
            case 'Q': translated_msg[i] = 'J';
                      break;
            case 'R': translated_msg[i] = 'I';
                      break;
            case 'S': translated_msg[i] = 'H';
                      break;
            case 'T': translated_msg[i] = 'G';
                      break;
            case 'U': translated_msg[i] = 'F';
                      break;
            case 'V': translated_msg[i] = 'E';
                      break;
            case 'W': translated_msg[i] = 'D';
                      break;
            case 'X': translated_msg[i] = 'C';
                      break;
            case 'Y': translated_msg[i] = 'B';
                      break;
            case 'Z': translated_msg[i] = 'A';
                      break;
            case ' ': translated_msg[i] = ' '; //keeping the spaces as is.
                      break;
            default:  printf("\n\nCannot translate character %c", alien_msg[i]);
                      break; //if character is other than the alphabets, don't translate.
        }
    }

    printf("\n\nTranslated message in English: %s", translated_msg);

    return 0; // code snippet ends.
}