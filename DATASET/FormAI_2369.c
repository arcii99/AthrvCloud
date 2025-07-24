//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORD_LEN 50
#define MAX_WORD_COUNT 500

//structure to hold word count
struct WordCount {
    char word[MAX_WORD_LEN];
    int count;
};

//function to compare two struct WordCount objects by count
int compareByCount(const void* a, const void* b)
{
    const struct WordCount* wc1 = (const struct WordCount*)a;
    const struct WordCount* wc2 = (const struct WordCount*)b;

    return (wc2->count - wc1->count);
}

//function to get the next word from a string
char* getNextWord(char* str)
{
    static int pos = 0;
    static char* staticStr = NULL;
    if (str != NULL) {
        pos = 0;
        staticStr = str;
    }

    //skip non alphabetic characters
    while (!isalpha(staticStr[pos]))
    {
        pos++;

        if (staticStr[pos] == '\0')
            return NULL;
    }

    int j = 0;
    char word[MAX_WORD_LEN];
    while (isalpha(staticStr[pos]) && (j < MAX_WORD_LEN - 1))
    {
        word[j++] = tolower(staticStr[pos++]);
    }
    word[j] = '\0';

    return strdup(word);
}

int main()
{
    struct WordCount wordList[MAX_WORD_COUNT]; //store the frequency of all the words
    char fileText[5000]; //store the entire text file
    char* word; //store the current word

    //read the text file
    printf("Enter text:\n");
    fgets(fileText, sizeof(fileText), stdin);

    //initialize the word counts to 0
    for (int i = 0; i < MAX_WORD_COUNT; i++) 
    {
        wordList[i].count = 0;
        strcpy(wordList[i].word, "");
    }

    //iterate through the text and count the frequency of each word
    word = getNextWord(fileText);
    while (word != NULL && wordList[MAX_WORD_COUNT - 1].count == 0) 
    {
        //look for the word in the word list
        int i = 0;
        while (wordList[i].count > 0 && strcmp(wordList[i].word, word) != 0) 
        {
            i++;
        }

        //update the word count
        strcpy(wordList[i].word, word);
        wordList[i].count++;

        free(word);
        word = getNextWord(NULL);
    }

    //sort the word list by count (descending order)
    qsort(wordList, MAX_WORD_COUNT, sizeof(struct WordCount), compareByCount);

    //output the word frequency
    printf("Word Frequency:\n");
    for (int i = 0; i < MAX_WORD_COUNT && wordList[i].count > 0; i++)
    {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }

    return 0;
}