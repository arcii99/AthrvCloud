//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: systematic
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100], temp[50], translation[1000] = "";
    int i, j;

    printf("Enter a sentence in C Cat language: ");
    gets(sentence);

    for (i = 0; i < strlen(sentence); i++)
    {
        if (sentence[i] == 'm' && sentence[i+1] == 'e' && sentence[i+2] == 'a' && sentence[i+3] == 'w')
        {
            strcat(translation, "Hello");
            i += 3;
        }
        else if (sentence[i] == 'p' && sentence[i+1] == 'u' && sentence[i+2] == 'r' && sentence[i+3] == 'r')
        {
            strcat(translation, "Goodbye");
            i += 3;
        }
        else if (sentence[i] == 'h' && sentence[i+1] == 'i' && sentence[i+2] == 's' && sentence[i+3] == 's')
        {
            strcat(translation, "Yes");
            i += 3;
        }
        else if (sentence[i] == 'n' && sentence[i+1] == 'a' && sentence[i+2] == 'w')
        {
            strcat(translation, "No");
            i += 2;
        }
        else if (sentence[i] == 'f' && sentence[i+1] == 'i' && sentence[i+2] == 's' && sentence[i+3] == 'h')
        {
            strcat(translation, "Food");
            i += 3;
        }
        else if (sentence[i] == 's' && sentence[i+1] == 'l' && sentence[i+2] == 'e' && sentence[i+3] == 'e' 
                 && sentence[i+4] == 'p')
        {
            strcat(translation, "Sleep");
            i += 4;
        }
        else if (sentence[i] == 'i' && sentence[i+1] == 't' && sentence[i+2] == 'c' && sentence[i+3] == 'h')
        {
            strcat(translation, "Scratch");
            i += 3;
        }
        else if (sentence[i] == 'r' && sentence[i+1] == 'a' && sentence[i+2] == 'w' && sentence[i+3] == 'r')
        {
            strcat(translation, "Mouse");
            i += 3;
        }
        else if (sentence[i] == 'm' && sentence[i+1] == 'e' && sentence[i+2] == 'o' && sentence[i+3] == 'w'
                 && sentence[i+4] == 't')
        {
            strcat(translation, "Thank you");
            i += 4;
        }
        else if (sentence[i] == 'p' && sentence[i+1] == 'u' && sentence[i+2] == 'r' && sentence[i+3] == 'r' 
                 && sentence[i+4] == 't')
        {
            strcat(translation, "I'm sorry");
            i += 4;
        }
        else if (sentence[i] == 'p' && sentence[i+1] == 'l' && sentence[i+2] == 'a' && sentence[i+3] == 'y')
        {
            strcat(translation, "Toy");
            i += 3;
        }
        else if (sentence[i] == 'r' && sentence[i+1] == 'u' && sentence[i+2] == 'n')
        {
            strcat(translation, "Chase");
            i += 2;
        }
        else
        {
            temp[0] = sentence[i];
            temp[1] = '\0';
            strcat(translation, temp);
        }
    }

    printf("Translation: %s\n", translation);

    return 0;
}