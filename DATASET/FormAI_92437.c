//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: modular
#include <stdio.h>
#include <string.h>

void translate_word(char alien[], char english[]);
void translate_sentence(char sentence[]);

int main()
{
    char sentence[100];
    
    printf("Enter an alien sentence:\n");
    fgets(sentence, sizeof(sentence), stdin); // read the input sentence
    
    printf("\nTranslated sentence:\n");
    translate_sentence(sentence); // translate the sentence
    
    return 0;
}

// function to translate a single alien word to English
void translate_word(char alien[], char english[])
{
    // Replace the following with your own mapping rules
    if(strcmp(alien, "Zorg") == 0) strcpy(english, "Hello");
    else if(strcmp(alien, "Bidbar") == 0) strcpy(english, "Goodbye");
    else strcpy(english, "Unknown word");
}

// function to translate an alien sentence to English
void translate_sentence(char sentence[])
{
    char *token, word[20], english[20], translated[100] = "";
    token = strtok(sentence, " .,!?\n");
    while(token != NULL)
    {
        strcpy(word, token);
        translate_word(word, english);
        strcat(translated, english);
        strcat(translated, " ");
        token = strtok(NULL, " .,!?\n");
    }
    printf("%s", translated);
}