//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: sophisticated
#include<stdio.h>
#include<string.h>

char* char_to_art(char c);

int main()
{
    char text[100];
    printf("Enter some text:\n");
    fgets(text, 100, stdin);

    int len = strlen(text);
    char ascii_art[len*6]; // Six characters needed for each ASCII art character

    for(int i=0; i<len; i++)
    {
        char* art = char_to_art(text[i]); // Get the ASCII art for the character
        strcat(ascii_art, art); // Add the ASCII art to the string
    }

    printf("\nGenerated ASCII art:\n%s", ascii_art);
    return 0;
}


char* char_to_art(char c)
{
    // Define the ASCII art for each character
    switch(c)
    {
        case ' ': return "     ";
        case 'a':
        case 'A': return "  /\\  \n /  \\ \n/ /\\ \\\n\\/  \\/\n      ";
        case 'b':
        case 'B': return "#### \n#   #\n#####\n#   #\n#### ";
        // Add more ASCII art definitions for each character
        // ...

        default: return "     "; // If the character is not supported, print a blank space
    }
}