//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertToMorse(char message[]);

int main()
{
      char message[100];
      printf("Enter your message: ");
      scanf("%[^\n]", message); // read the whole line

      convertToMorse(message); // call the function to convert to Morse code

      return 0;
}

void convertToMorse(char message[])
{
    char *morseCode[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};

    int len = strlen(message);
    printf("Morse code: ");
    for(int i=0; i<len; i++) 
    {
        if(isalpha(message[i]))
        {
            int index = tolower(message[i]) - 'a';
            printf("%s ", morseCode[index]); // print morse code
        }
        else if(message[i] == ' ') {
            printf("  "); // double space for blank spaces
        }
        else {
            printf("%c ", message[i]); // print other non alpha characters (including numbers)
        }
    }
}