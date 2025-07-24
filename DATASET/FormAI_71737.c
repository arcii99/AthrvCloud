//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: complex
#include <stdio.h>
#include <string.h>

char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"}; //Morse code array

char *text_to_morse(char *text) //Function to convert text to Morse code
{
    int i, j;
    char *morse_text = ""; //Empty string for storing Morse code
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z') //If lowercase letter
        {
            j = (int)text[i] - 97; //Find index of letter in Morse code array
            strcat(morse_text, morse_code[j]); //Append Morse code to string
        }
        else if (text[i] >= 'A' && text[i] <= 'Z') //If uppercase letter
        {
            j = (int)text[i] - 65; //Find index of letter in Morse code array
            strcat(morse_text, morse_code[j]); //Append Morse code to string
        }
        else if (text[i] == ' ') //If space
        {
            strcat(morse_text, " "); //Append space to string
        }
        else //If any other character (e.g. punctuation)
        {
            strcat(morse_text, "?"); //Append question mark to string
        }
        strcat(morse_text, " "); //Append space to separate characters
    }
    return morse_text; //Return Morse code string
}

int main()
{
    char text[100];
    printf("Enter text to convert to Morse code: ");
    fgets(text, 100, stdin); //Get input text
    text[strcspn(text, "\n")] = 0; //Remove newline character
    char *morse_text;
    morse_text = text_to_morse(text); //Convert text to Morse code
    printf("%s\n", morse_text); //Print Morse code
    return 0;
}