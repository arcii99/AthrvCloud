//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: lively
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    char morseCodes [36][6] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};	// Morse Code Table
    char input[100]; // Declare a string variable to hold user input
    printf("Enter the text to be converted to morse code:\n");
    fgets(input,100,stdin); // Get user input
    printf("\nMorse Code: ");
    for(int i=0 ; i < strlen(input) ; i++)  // Loop through every character in the input string
    {
        if(isalpha(input[i])) // Check if the character is alphabetic
        {   
            int index = toupper(input[i])-'A';
            printf("%s ", morseCodes[index]); // Print the corresponding morse code for the character
        }
        else if(input[i] == ' ')
        {
            printf("/ "); // Print a forward slash for spaces
        }
        else if(isdigit(input[i]))
        {
            int index = input[i]-'0' + 25;   // Morse Code for digits start from array index 25 ('0'-'9' => 25-34)
            printf("%s ", morseCodes[index]); // Print the corresponding morse code for the digit
        }
    }
    return 0;
}