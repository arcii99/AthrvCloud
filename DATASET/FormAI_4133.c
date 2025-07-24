//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: romantic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void convertToMorseCode(char *input, char *output);

int main()
{
    char input[1000], output[4000];
    
    printf("Enter your romantic text to convert to Morse Code: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // removes the newline character added by fgets
    
    convertToMorseCode(input, output);
    printf("Morse Code: %s\n", output);
    
    return 0;
}

void convertToMorseCode(char *input, char *output)
{
    // define Morse Code table as arrays of strings
    char *letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    char *numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
    
    int length = strlen(input);
    int outputIndex = 0;
    
    for(int i = 0; i < length; i++)
    {
        char c = tolower(input[i]); // convert character to lowercase
        
        if(c == ' ')
        {
            strcat(output, "   "); // add three spaces for word gap
            outputIndex += 3;
        }
        else if(c >= 'a' && c <= 'z')
        {
            int index = c - 'a';
            strcat(output, letters[index]);
            outputIndex += strlen(letters[index]);
            
            if(i < length-1 && input[i+1] != ' ')
            {
                strcat(output, " ");
                outputIndex += 1;
            }
        }
        else if(c >= '0' && c <= '9')
        {
            int index = c - '0';
            strcat(output, numbers[index]);
            outputIndex += strlen(numbers[index]);
            
            if(i < length-1 && input[i+1] != ' ')
            {
                strcat(output, " ");
                outputIndex += 1;
            }
        }
    }
}