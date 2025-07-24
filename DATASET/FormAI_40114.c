//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: calm
#include <stdio.h>
#include <string.h>

int main()
{
    char cat_word[20];
    
    printf("Welcome to the Cat Language Translator!\n");
    printf("Please enter a word in Cat language: ");
    
    scanf("%s", cat_word);
    
    // Check if input word is a known word in Cat language
    if(strcmp(cat_word, "meow") == 0)
    {
        printf("Translation: Hello!\n");
    }
    else if(strcmp(cat_word, "hiss") == 0)
    {
        printf("Translation: Leave me alone!\n");
    }
    else if(strcmp(cat_word, "purr") == 0)
    {
        printf("Translation: I am happy and content.\n");
    }
    else
    {
        printf("Translation: I don't know what that means in Cat language.\n");
    }
    
    return 0;
}