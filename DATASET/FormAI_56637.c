//FormAI DATASET v1.0 Category: Spell checking ; Style: introspective
//This program checks the spelling of a sentence.
//It uses an introspective approach to understand the rules of spelling.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Function prototypes
int checkSpelling(char word[]);
int checkVowel(char letter);
int checkDouble(char letter, char nextLetter);
int checkY(char letter);

int main()
{
    //Declare variables
    char sentence[200];
    char word[20];
    int i, j, k;

    //Get user input
    printf("Enter a sentence: ");
    fgets(sentence, 200, stdin);

    //Check each word in the sentence
    for(i = 0, j = 0; sentence[i] != '\0'; i++)
    {
        if(isalpha(sentence[i]))
        {
            //Add letter to current word
            word[j] = tolower(sentence[i]);
            j++;
        }
        else if(j > 0)
        {
            //End current word
            word[j] = '\0';
            j = 0;

            //Check if word is spelled correctly
            int result = checkSpelling(word);
            if(result == 1)
            {
                printf("%s is spelled correctly.\n", word);
            }
            else
            {
                printf("%s is not spelled correctly.\n", word);

                //Suggest possible corrections
                printf("Possible corrections: ");
                for(k = 0; k < strlen(word); k++)
                {
                    char temp = word[k];

                    //Replace each letter in the word
                    for(char letter = 'a'; letter <= 'z'; letter++)
                    {
                        word[k] = letter;
                        int result = checkSpelling(word);
                        if(result == 1)
                        {
                            printf("%s ", word);
                        }
                    }

                    //Reset the letter
                    word[k] = temp;
                }

                //End the line
                printf("\n");
            }
        }
    }

    return 0;
}

/*
    Check if a word is spelled correctly.
    Returns 1 for correct and 0 for incorrect.
*/
int checkSpelling(char word[])
{
    int i;

    //Check for special cases
    if(strcmp(word, "i") == 0 || strcmp(word, "a") == 0)
    {
        return 1;
    }

    //Check each letter in the word
    for(i = 0; i < strlen(word); i++)
    {
        char letter = word[i];

        //Check if the letter is a vowel
        if(checkVowel(letter))
        {
            continue;
        }

        //Check for double letters
        if(checkDouble(letter, word[i+1]))
        {
            i++;
            continue;
        }

        //Check for y rule
        if(checkY(letter))
        {
            continue;
        }

        //Letter is not spelled correctly
        return 0;
    }

    //Word is spelled correctly
    return 1;
}

/*
    Check if a letter is a vowel.
    Returns 1 for vowel and 0 for consonant.
*/
int checkVowel(char letter)
{
    return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');
}

/*
    Check for double letters.
    Returns 1 for double and 0 for single.
*/
int checkDouble(char letter, char nextLetter)
{
    return (letter == nextLetter);
}

/*
    Check for y rule.
    Returns 1 for y and 0 for not y.
*/
int checkY(char letter)
{
    return (letter == 'y');
}