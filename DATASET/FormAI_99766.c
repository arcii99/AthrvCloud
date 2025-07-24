//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: peaceful
#include<stdio.h>
#include<string.h>

int main()
{
    char c_cat_language[100], translated_language[100], peaceful_word[100];
    int i, j, k;

    // greeting message to the user
    printf("Welcome to C Cat Language Peaceful Translator\n");

    //accepting input from user
    printf("\nEnter the C cat language to translate into a peaceful language:\n");
    fgets(c_cat_language, 100, stdin);
    c_cat_language[strcspn(c_cat_language, "\n")] = 0;

    //converting C cat language to peaceful language
    for(i=0, j=0; c_cat_language[i]!='\0'; i++, j++)
    {
        if(c_cat_language[i]=='C')
        {
            translated_language[j] = 'P';
            peaceful_word[j] = 'Peace';
            j++;
        }
        translated_language[j] = c_cat_language[i];
        peaceful_word[j] = c_cat_language[i];
    }
    translated_language[j] = '\0';
    peaceful_word[j] = '\0';

    //displaying the translated C cat language in a peaceful language
    printf("\nYour C cat language, \"%s\" in a peaceful language is:\n", c_cat_language);
    printf("%s\n", peaceful_word);

    //displaying a peaceful message
    printf("\nMay peace be with you always!\n");

    return 0;
}