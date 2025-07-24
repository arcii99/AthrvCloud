//FormAI DATASET v1.0 Category: Text processing ; Style: surrealist
#include<stdio.h>
#include<ctype.h>
#include<string.h>

//Create an array to hold the surrealist words
char words [][20] = {"fish-clock", "umbrella-jellyfish", "fly-bicycle", "balloon-tree", "window-rain"};

//Create a function to convert characters to a random uppercase/lowercase mix
char getRandomCase(char c)
{
    if (rand() % 2 == 0)
    {
        return toupper(c);
    }
    else
    {
        return tolower(c);
    }
}

int main()
{
    char sentence[1000]; //Create an array to hold the input sentence
    printf("Enter a sentence to surrealist-ify: ");
    fgets(sentence, 1000, stdin); //Read in the input sentence
    
    printf("\nYour surrealist sentence: ");
    
    //Loop through the sentence one character at a time
    for (int i = 0; i < strlen(sentence); i++)
    {
        if (isalpha(sentence[i])) //Check if the character is a letter
        {
            printf("%c", getRandomCase(sentence[i])); //Print a random uppercase/lowercase version of the letter
        }
        else if (sentence[i] == ' ') //Check if the character is a space
        {
            printf(" "); //Print a space
        }
        else //If the character is not a letter or a space, replace it with a random surrealist word
        {
            printf("%s", words[rand() % 5]);
        }
    }
    
    return 0;
}