//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: paranoid
#include<stdio.h>
#include<string.h>

// Function to convert the text to Morse code
void text_to_morse(char text[], char morse[])
{
    int i, j = 0;
    char morse_code[27][6] = {".-", "-...", "-.-.", "-..", ".", 
                              "..-.", "--.", "....", "..", ".---",
                              "-.-", ".-..", "--", "-.", "---", 
                              ".--.", "--.-", ".-.", "...", "-", 
                              "..-", "...-", ".--", "-..-", "-.--", "--.."};

    // Convert each character of the text to Morse code
    for(i = 0; i < strlen(text); i++)
    {
        if(text[i] >= 'a' && text[i] <= 'z')
        {
            strcpy(&morse[j], morse_code[text[i] - 97]);
        }
        else if(text[i] >= 'A' && text[i] <= 'Z')
        {
            strcpy(&morse[j], morse_code[text[i] - 65]);
        }
        else if(text[i] == ' ')
        {
            morse[j] = ' ';
        }
        j += strlen(&morse[j]);
    }
    morse[j] = '\0';
}

int main()
{
    char text[100], morse[200];
    
    printf("Enter the text to convert to Morse code:\n");
    fgets(text, 100, stdin);

    // Remove the newline character from the input
    if(text[strlen(text)-1] == '\n')
    {
        text[strlen(text)-1] = '\0';
    }

    // Convert the text to Morse code using the paranoid style
    text_to_morse(text, morse);
    printf("The Morse code is:\n");

    // Print the Morse code with paranoid spacing
    int i, j;
    for(i = 0; i < strlen(morse); i++)
    {
        if(morse[i] == '.')
        {
            printf(".");
            for(j = 0; j < 6; j++)
            {
                if(morse[i+j] != '.')
                {
                    break;
                }
                else
                {
                    i++;
                }
            }
        }
        else if(morse[i] == '-')
        {
            printf("-");
            for(j = 0; j < 6; j++)
            {
                if(morse[i+j] != '-')
                {
                    break;
                }
                else
                {
                    i++;
                }
            }
        }
        else if(morse[i] == ' ')
        {
            printf("   ");
        }

        if(morse[i+1] != '.' && morse[i+1] != '-' && morse[i+1] != ' ' && i != strlen(morse)-1)
        {
            printf(" ");
        }
    }

    return 0;
}