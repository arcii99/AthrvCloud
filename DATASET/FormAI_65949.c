//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: accurate
//C Cat Language Translator
#include <stdio.h>
#include <string.h>

//function to translate the word
void translate(char word[])
{
    if(strcmp(word,"meow")==0)
        printf("Hello");
    else if(strcmp(word,"purr")==0)
        printf("Thank you");
    else if(strcmp(word,"hiss")==0)
        printf("I don't like this");
    else if(strcmp(word,"scratch")==0)
        printf("Stop that");
    else if(strcmp(word,"food")==0)
        printf("I'm hungry");
    else if(strcmp(word,"sleep")==0)
        printf("I'm tired");
    else
        printf("I don't understand this word");
}

int main()
{
    char sentence[100];
    printf("Enter a sentence in C Cat Language: ");
    fgets(sentence,100,stdin);

    printf("\nTranslated sentence: ");
    char *word = strtok(sentence," ");
    while(word!=NULL)
    {
        translate(word);
        printf(" ");
        word = strtok(NULL," ");
    }
    printf("\n");
    return 0;
}