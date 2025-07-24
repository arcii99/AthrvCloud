//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: accurate
#include<stdio.h>
#include<string.h>

void morse(char *str) // Function to convert string to Morse code
{
    char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                          ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
                          "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " "}; // Morse code dictionary
    char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

    printf("\nMorse Code: ");

    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        char c = toupper(str[i]); // Convert characters to uppercase
        for(int j=0; j<27; j++)
        {
            if(c == alpha[j])
            {
                printf("%s ", morse_code[j]); // Print corresponding Morse code for the current character
                break;
            }
        }
    }
}

int main()
{
    char input[50];
    printf("Enter a string to convert to Morse code: ");
    fgets(input, 50, stdin);
    printf("Input: %s", input);

    morse(input); // Call function to convert string to Morse code

    return 0;
}