//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* alien_language(char* input)
{
    char* output = (char*) malloc(sizeof(char) * strlen(input)); // allocate memory for the output string
    int length = strlen(input); // get the length of the input string
    
    for(int i=0; i<length; i++) // iterate through the input string
    {
        switch(input[i])
        {
            case 'A':
                output[i] = 'Z'; // 'A' becomes 'Z'
                break;
            case 'B':
                output[i] = 'Y'; // 'B' becomes 'Y'
                break;
            case 'C':
                output[i] = 'X'; // 'C' becomes 'X'
                break;
            case 'D':
                output[i] = 'W'; // 'D' becomes 'W'
                break;
            case 'E':
                output[i] = 'V'; // 'E' becomes 'V'
                break;
            case 'F':
                output[i] = 'U'; // 'F' becomes 'U'
                break;
            case 'G':
                output[i] = 'T'; // 'G' becomes 'T'
                break;
            case 'H':
                output[i] = 'S'; // 'H' becomes 'S'
                break;
            case 'I':
                output[i] = 'R'; // 'I' becomes 'R'
                break;
            case 'J':
                output[i] = 'Q'; // 'J' becomes 'Q'
                break;
            case 'K':
                output[i] = 'P'; // 'K' becomes 'P'
                break;
            case 'L':
                output[i] = 'O'; // 'L' becomes 'O'
                break;
            case 'M':
                output[i] = 'N'; // 'M' becomes 'N'
                break;
            case 'N':
                output[i] = 'M'; // 'N' becomes 'M'
                break;
            case 'O':
                output[i] = 'L'; // 'O' becomes 'L'
                break;
            case 'P':
                output[i] = 'K'; // 'P' becomes 'K'
                break;
            case 'Q':
                output[i] = 'J'; // 'Q' becomes 'J'
                break;
            case 'R':
                output[i] = 'I'; // 'R' becomes 'I'
                break;
            case 'S':
                output[i] = 'H'; // 'S' becomes 'H'
                break;
            case 'T':
                output[i] = 'G'; // 'T' becomes 'G'
                break;
            case 'U':
                output[i] = 'F'; // 'U' becomes 'F'
                break;
            case 'V':
                output[i] = 'E'; // 'V' becomes 'E'
                break;
            case 'W':
                output[i] = 'D'; // 'W' becomes 'D'
                break;
            case 'X':
                output[i] = 'C'; // 'X' becomes 'C'
                break;
            case 'Y':
                output[i] = 'B'; // 'Y' becomes 'B'
                break;
            case 'Z':
                output[i] = 'A'; // 'Z' becomes 'A'
                break;
            default: // if the character is not a letter, do not modify it
                output[i] = input[i];
                break;
        }
    }
    
    return output; // return the output string
}

int main()
{
    char input[] = "Hello World!"; // test input string
    char* output = alien_language(input); // translate the input string using the alien_language function
    
    printf("Input: %s\nOutput: %s\n", input, output); // print the input and output strings
    
    free(output); // free the memory allocated for the output string
    
    return 0; // return 0 to indicate successful completion of the program
}