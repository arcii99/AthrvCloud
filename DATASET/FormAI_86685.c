//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100];

    printf("Enter a sentence in C Cat Language:\n");
    fgets(sentence, 100, stdin);

    int length = strlen(sentence);

    for(int i=0; i<length; i++)
    {
        if(sentence[i] == 'c') // If "c" is in the sentence
        {
            printf("Meow "); // Translate to "Meow"
        }
        else if(sentence[i] == 'C') // If "C" is in the sentence
        {
            printf("MEOW "); // Translate to "MEOW"
        }
        else
        {
            printf("%c", sentence[i]); // Print out the character as is
        }
    }

    return 0;
}