//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: cheerful
#include <stdio.h>
#include <string.h>

//Morse Code Conversion Function
void MorseCode(char *message, char *morse)
{
    int i, j;
    char code[37][7] = {" ", "--..--", ".-.-.-", "..--..", ".----.", "-.-.--", 
                        ".-..-.", ".-...", "-.--.", "-.--.-", ".-.", "...", 
                        "-", "..-", "...-", ".--", "-..-", "-.--", "--.", 
                        "-.---", "--..", "--.-", ".-.-.", "---...", ".--.-.", 
                        "-...-", ".----", "..---", "...--", "....-", ".....", 
                        "-....", "--...", "---..", "----.", "-----"};
    //Converting the message into Morse Code
    for(i=0; i<strlen(message); i++)
    {
        if(message[i] == '\n')  //Check for new line character
            strcat(morse, "\n"); //Add new line character to Morse Code
        else
        {
            for(j=0; j<37; j++)
            {
                if(message[i] == code[j][0])
                {
                    strcat(morse, code[j]+1); //Add Morse Code for respective character
                    strcat(morse, " "); //Add space in Morse Code for the next character
                }
            }
        }
    }
}

int main(void)
{
    char message[1000];
    char morse[2000] = "";

    printf("Welcome to the Morse Code Conversion Program!\n\n");
    printf("Please enter the text message: ");

    fgets(message, 1000, stdin); //Get the message to be converted from user

    MorseCode(message, morse); //Call MorseCode function to convert message to Morse Code

    printf("\nYour message in Morse Code is: \n\n%s\n", morse); //Display the converted Morse Code message

    printf("\nThank you for using the Morse Code Conversion Program! Have a great day! :)\n");

    return 0; 
}