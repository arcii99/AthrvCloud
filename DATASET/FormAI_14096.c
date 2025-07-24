//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: recursive
#include <stdio.h>
#include <string.h>

// C Cat Language to English dictionary
char* cat_to_eng(char *word)
{
    if(strcmp(word, "meow") == 0)
        return "hello";
    else if(strcmp(word, "purr") == 0)
        return "thank you";
    else if(strcmp(word, "hiss") == 0)
        return "goodbye";
    else if(strcmp(word, "scratch") == 0)
        return "stop";
    else if(strcmp(word, "play") == 0)
        return "let's have fun";
    else
        return "Unknown cat word";
}

// Cat language translator function
void cat_translator(char *sentence)
{
    char *word = strtok(sentence, " ");
    
    if(word != NULL)
    {
        printf("%s ", cat_to_eng(word));
        cat_translator(NULL);
    }
}

int main()
{
    char sentence[50];
    
    printf("Enter a sentence in Cat language: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    printf("Translated sentence: ");
    cat_translator(sentence);
    
    return 0;
}