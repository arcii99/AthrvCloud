//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

//function to translate Alien Language to English
void translate(char* alien)
{
    if (strcmp(alien, "Kluh") == 0)
    {
        printf("Hello");
    }
    else if (strcmp(alien, "Zor") == 0)
    {
        printf("Goodbye");
    }
    else if (strcmp(alien, "Xenox") == 0)
    {
        printf("How are you?");
    }
    else if (strcmp(alien, "Galaxia") == 0)
    {
        printf("Thank you");
    }
    else
    {
        printf("I cannot translate that word.");
    }
}

int main()
{
    char alien[20];
    printf("Enter an Alien word: ");
    scanf("%s", alien); //read in the Alien word
    
    //call the translate function
    translate(alien);

    return 0;
}