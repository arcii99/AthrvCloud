//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: complex
#include <stdio.h>
#include <string.h>

#define NUM_OF_WORDS 9
#define MAX_WORD_LENGTH 15
#define MAX_INPUT_LENGTH 100

const char inputWords[NUM_OF_WORDS][MAX_WORD_LENGTH] = {
    "meow", "purr", "hiss", "scratch", "nap",
    "mouse", "fish", "bird", "lounge"
};

const char translatedWords[NUM_OF_WORDS][MAX_WORD_LENGTH] = {
    "hello", "i am content", "i am angry", "i need attention", "i am sleepy",
    "i want to play", "i want food", "i want to hunt", "i want to relax"
};

// function declarations
void printWords();
int isWord(char *word);
void translate(char *input, char *output);

int main()
{
    // print available words and their translations
    printWords();

    char input[MAX_INPUT_LENGTH];
    printf("\nEnter a sentence in C Cat Language: ");
    fgets(input, sizeof(input), stdin);

    // remove newline character from input
    input[strcspn(input, "\n")] = 0;

    char output[MAX_INPUT_LENGTH];
    translate(input, output);

    printf("Translated sentence: %s\n", output);

    return 0;
}

void printWords()
{
    printf("Words available for translation:\n");
    for (int i = 0; i < NUM_OF_WORDS; i++)
    {
        printf("%s -> %s\n", inputWords[i], translatedWords[i]);
    }
}

int isWord(char *word)
{
    for (int i = 0; i < NUM_OF_WORDS; i++)
    {
        if (strcmp(word, inputWords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void translate(char *input, char *output)
{
    char *token = strtok(input, " ");
    while (token != NULL)
    {
        if (isWord(token))
        {
            for (int i = 0; i < NUM_OF_WORDS; i++)
            {
                if (strcmp(token, inputWords[i]) == 0)
                {
                    strcat(output, translatedWords[i]);
                    strcat(output, " ");
                }
            }
        }
        else
        {
            strcat(output, token);
            strcat(output, " ");
        }
        token = strtok(NULL, " ");
    }
}