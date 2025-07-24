//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: excited
#include<stdio.h>
#include<string.h>

int main()
{
    char message[100], ch;
    int i, j;
    printf("Welcome to the exciting Morse code converter!\n");
    printf("Enter the message you want to convert:\n");
    fgets(message, 100, stdin);

    char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
                          ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", 
                          ".--", "-..-", "-.--", "--..", "/", ".----", "..---", "...--", "....-", ".....",
                          "-....", "--...", "---..", "----.", "-----"};

    printf("Your message in Morse code is:\n");

    for(i=0; message[i] != '\0'; i++)
    {
        ch = message[i];

        if(ch == ' ')
        {
            printf(" ");
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            j = ch - 'A';
            printf("%s ", morse_code[j]);
        }
        else if(ch >= 'a' && ch <= 'z')
        {
            j = ch - 'a';
            printf("%s ", morse_code[j]);
        }
        else if(ch >= '0' && ch <= '9')
        {
            j = ch - '0' + 26;
            printf("%s ", morse_code[j]);
        }
        else
        {
            printf("\nOops! We couldn't recognize the character: '%c'. But we won't give up!\n", ch);
        }
    }

    printf("\nThank you for using exciting Morse code converter!\n");

    return 0;
}