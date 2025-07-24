//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: futuristic
#include <stdio.h>
#include <string.h>

/* This program is a C Alien Language Translator */
/* It can translate a message from the alien language into English */

int main()
{
    char alien_message[100];
    int option;

    printf("\nWelcome to the C Alien Language Translator!\n");

    do {
        printf("\nSelect an option:\n");
        printf("1. Translate Alien Language message to English\n");
        printf("2. Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter the Alien Language message:\n");
                scanf("%s", alien_message);
                translate(alien_message);
                break;
            case 2:
                printf("\nExiting the program...\n");
                break;
            default:
                printf("\nInvalid option, please try again.\n");
        }

    } while(option != 2);

    return 0;
}

/* This function translates the Alien Language message into English */
void translate(char str[])
{
    int i;
    char english_message[100];

    for(i = 0; str[i]; i++) {
        switch(str[i]) {
            case 'a':
                english_message[i] = 'z';
                break;
            case 'b':
                english_message[i] = 'y';
                break;
            case 'c':
                english_message[i] = 'x';
                break;
            case 'd':
                english_message[i] = 'w';
                break;
            case 'e':
                english_message[i] = 'v';
                break;
            case 'f':
                english_message[i] = 'u';
                break;
            case 'g':
                english_message[i] = 't';
                break;
            case 'h':
                english_message[i] = 's';
                break;
            case 'i':
                english_message[i] = 'r';
                break;
            case 'j':
                english_message[i] = 'q';
                break;
            case 'k':
                english_message[i] = 'p';
                break;
            case 'l':
                english_message[i] = 'o';
                break;
            case 'm':
                english_message[i] = 'n';
                break;
            case 'n':
                english_message[i] = 'm';
                break;
            case 'o':
                english_message[i] = 'l';
                break;
            case 'p':
                english_message[i] = 'k';
                break;
            case 'q':
                english_message[i] = 'j';
                break;
            case 'r':
                english_message[i] = 'i';
                break;
            case 's':
                english_message[i] = 'h';
                break;
            case 't':
                english_message[i] = 'g';
                break;
            case 'u':
                english_message[i] = 'f';
                break;
            case 'v':
                english_message[i] = 'e';
                break;
            case 'w':
                english_message[i] = 'd';
                break;
            case 'x':
                english_message[i] = 'c';
                break;
            case 'y':
                english_message[i] = 'b';
                break;
            case 'z':
                english_message[i] = 'a';
                break;
            default:
                english_message[i] = str[i];
                break;
        }
    }

    english_message[i] = '\0'; /* Add null character at the end of the string */

    printf("\nThe English message is: %s\n", english_message);
}