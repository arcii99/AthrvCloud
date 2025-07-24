//FormAI DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main()
{
    char input[200]; //declare a character array to hold the input string
    int vowels = 0, consonants = 0, digits = 0, spaces = 0; //initialize counters for each type of character

    printf("Please enter a sentence:\n"); //prompt user for input
    fgets(input, sizeof(input), stdin); //read input using fgets, which allows spaces and specifies the limit of the input buffer

    for (int i = 0; i < strlen(input); i++) //loop through each character in the input string
    {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) //check if the character is a letter
        {
            if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') //check if the character is a vowel
            {
                vowels++;
            }
            else //if the character is not a vowel, it must be a consonant
            {
                consonants++;
            }
        }
        else if (input[i] >= '0' && input[i] <= '9') //check if the character is a digit
        {
            digits++;
        }
        else if (input[i] == ' ') //check if the character is a space
        {
            spaces++;
        }
    }

    printf("\nThe input contains:\n"); //print out the results
    printf("%d vowels\n", vowels);
    printf("%d consonants\n", consonants);
    printf("%d digits\n", digits);
    printf("%d spaces\n", spaces);

    return 0;
}