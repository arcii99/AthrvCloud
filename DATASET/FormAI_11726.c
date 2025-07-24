//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove punctuations in the input string
char* removePunctuations(char* str)
{
    int i = 0, j = 0;
    char c;
    while ((c = str[i++]) != '\0')
    {
        if (isalnum(c))
            str[j++] = tolower(c);
    }
    str[j] = '\0';
    return str;
}

// Function to increment the frequency of a word in the HashMap
void incrementCount(char* word, int* freqMap)
{
    unsigned long long hash = 5381;
    int c;
    while ((c = *word++))
        hash = ((hash << 5) + hash) + c; // calculating hash value
    int index = hash % 100000; // hash index
    while (freqMap[index] != 0)
    {
        if (strcmp(word, (char*)(freqMap + index + 1)) == 0) // word found in the HashMap
        {
            freqMap[index]++; // increment frequency count
            return;
        }
        index++;
        if (index == 100000) // loop around
            index = 0;
    }
    if (strcpy((char*)(freqMap + index + 1), word) == NULL) // adding new word to the HashMap
    {
        printf("Error: Out of memory.\n");
        exit(1);
    }
    freqMap[index] = 1;
}

// Function to print the frequency count of each word in the HashMap
void printFrequency(int* freqMap)
{
    printf("Word\tFrequency\n");
    for (int i = 0; i < 100000; i++)
    {
        if (freqMap[i] != 0)
        {
            printf("%s\t%d\n", (char*)(freqMap + i + 1), freqMap[i]);
        }
    }
}

int main()
{
    char text[100000];
    printf("Enter text (maximum 100,000 characters):\n");
    fgets(text, 100000, stdin); // read input text
    char* words[100000];
    int numWords = 0;
    char* token = strtok(text, " "); // get first word
    while (token != NULL)
    {
        token = removePunctuations(token); // remove punctuations from word
        words[numWords++] = token; // add word to array
        token = strtok(NULL, " "); // get next word
    }
    int freqMap[100000] = {0};
    for (int i = 0; i < numWords; i++)
        incrementCount(words[i], freqMap); // count frequency of each word and add to HashMap
    printFrequency(freqMap); // print the frequency count of each word
    return 0;
}