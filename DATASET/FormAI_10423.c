//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: energetic
// Welcome to the Morse Code Converting Program!
// This program will take your text input and convert it to Morse Code in a flash!

#include<stdio.h>
#include<string.h>

// The Morse Code Function
void morseCode(char ch)
{
    // Switching the character to find the morse code equivalent and printing it on the screen.
    switch (toupper(ch))
    {
        case 'A' :
            printf(".- ");
            break;
        case 'B' :
            printf("-... ");
            break;
        case 'C' :
            printf("-.-. ");
            break;
        case 'D' :
            printf("-.. ");
            break;
        case 'E' :
            printf(". ");
            break;
        case 'F' :
            printf("..-. ");
            break;
        case 'G' :
            printf("--. ");
            break;
        case 'H' :
            printf(".... ");
            break;
        case 'I' :
            printf(".. ");
            break;
        case 'J' :
            printf(".--- ");
            break;
        case 'K' :
            printf("-.- ");
            break;
        case 'L' :
            printf(".-.. ");
            break;
        case 'M' :
            printf("-- ");
            break;
        case 'N' :
            printf("-. ");
            break;
        case 'O' :
            printf("--- ");
            break;
        case 'P' :
            printf(".--. ");
            break;
        case 'Q' :
            printf("--.- ");
            break;
        case 'R' :
            printf(".-. ");
            break;
        case 'S' :
            printf("... ");
            break;
        case 'T' :
            printf("- ");
            break;
        case 'U' :
            printf("..- ");
            break;
        case 'V' :
            printf("...- ");
            break;
        case 'W' :
            printf(".-- ");
            break;
        case 'X' :
            printf("-..- ");
            break;
        case 'Y' :
            printf("-.-- ");
            break;
        case 'Z' :
            printf("--.. ");
            break;
        case '0' :
            printf("----- ");
            break;
        case '1' :
            printf(".---- ");
            break;
        case '2' :
            printf("..--- ");
            break;
        case '3' :
            printf("...-- ");
            break;
        case '4' :
            printf("....- ");
            break;
        case '5' :
            printf("..... ");
            break;
        case '6' :
            printf("-.... ");
            break;
        case '7' :
            printf("--... ");
            break;
        case '8' :
            printf("---.. ");
            break;
        case '9' :
            printf("----. ");
            break;
        case ' ' :
            printf("/ ");
            break;

        default :
            printf(" !ERROR! ");
    }
}

// The main function
int main()
{
    // Welcome messages
    printf("Hello there! I am the ultimate Morse Code Converter!\n");
    printf("As soon as you hit the Enter Key, I will convert the text you enter to Morse Code.\n");
    printf("--------------------------------------------------------\n");

    // Variable Declarations
    char string[100];
    int i, length;

    // Reading the Input String
    printf("\nEnter the string you want to convert to Morse Code:\n");
    fgets(string,100,stdin);
    length = strlen(string);

    // Removing the enter key from the end of the string, if present.
    if (string[length - 1] == '\n')
    {
        string[length - 1] = '\0';
    }

    // Converting the Text to Morse Code
    printf("\nConverting your Text to Morse Code...\n");
    for(i=0; i<length; i++)
    {
        morseCode(string[i]);
    }

    // The Final Message
    printf("\n\nThere you go! Your Text has been Converted to Morse Code!\nThank you for using our Program!\n");

    // End of the Code
    return 0;
}