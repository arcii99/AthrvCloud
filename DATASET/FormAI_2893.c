//FormAI DATASET v1.0 Category: Spell checking ; Style: irregular
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

/* This program checks for the correct spelling of a word using a hash table */
#define HASH_TABLE_SIZE 2053

struct KeyValuePair
{
    char key[50];
    bool value;
};

struct KeyValuePair hashTable[HASH_TABLE_SIZE];

void initHashTable()
{
    for(int i=0; i<HASH_TABLE_SIZE; i++)
    {
        strcpy(hashTable[i].key, "");
        hashTable[i].value = false;
    }
}

int calcHash(const char* str)
{
    int hash = 5381;
    while (*str)
        hash = (hash * 33 + *str++) % HASH_TABLE_SIZE;
    return hash % HASH_TABLE_SIZE;
}

bool checkSpelling(const char* word)
{
    int hash = calcHash(word);
    if (strcmp(hashTable[hash].key, word) == 0)
    {
        return hashTable[hash].value;
    }
    return false;
}

void insertWord(const char* word, bool isCorrect)
{
    int hash = calcHash(word);
    if (strcmp(hashTable[hash].key, "") == 0)
    {
        strcpy(hashTable[hash].key, word);
        hashTable[hash].value = isCorrect;
    }
}

int main()
{
    initHashTable();

    // Insert some words into the hash table
    insertWord("hello", true);
    insertWord("world", true);
    insertWord("speling", false);

    // Check some words for spelling
    if (checkSpelling("hello"))
        printf("hello is spelled correctly!\n");
    else
        printf("hello is spelled incorrectly!\n");

    if (checkSpelling("worlld"))
        printf("worlld is spelled correctly!\n");
    else
        printf("worlld is spelled incorrectly!\n");

    if (checkSpelling("spelling"))
        printf("spelling is spelled correctly!\n");
    else
        printf("spelling is spelled incorrectly!\n");

    return 0;
}