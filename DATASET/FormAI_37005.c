//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: cheerful
// Welcome to the C Cat Language Translator Program!
// Meow! Let's get started with some fun code!

#include <stdio.h>
#include <string.h>

int main()
{
    char english_sentence[100]; // set a limit on the sentence length

    // prompt the user to input an English sentence to translate
    printf("Meow! Please enter an English sentence to translate into C Cat Language: ");
    fgets(english_sentence, 100, stdin);
    
    // loop through each character of the sentence and translate it to C Cat Language
    for(int i = 0; i < strlen(english_sentence); i++)
    {
        if(english_sentence[i] == ' ') // if the character is a space, keep as is
        {
            printf("%c", english_sentence[i]);
        }
        else if(english_sentence[i] == 'a' || english_sentence[i] == 'A')
        {
            printf("meow ");
        }
        else if(english_sentence[i] == 'b' || english_sentence[i] == 'B')
        {
            printf("purr ");
        }
        else if(english_sentence[i] == 'c' || english_sentence[i] == 'C')
        {
            printf("hiss ");
        }
        else if(english_sentence[i] == 'd' || english_sentence[i] == 'D')
        {
            printf("growl ");
        }
        // continue with more translation options for each letter of the alphabet!
        // feel free to get creative with your translations, too!
        else
        {
            printf("%c", english_sentence[i]); // if the character is not a letter of the alphabet, keep as is
        }
    }
    printf("\nMeow, your sentence translated to C Cat Language! Hope you enjoyed this fun program!");
    
    return 0;
}