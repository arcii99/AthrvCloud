//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: inquisitive
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_WORD_LENGTH 100
//Function to count word frequency
int countFrequency(char *word, char *str) {
    int count = 0;
    char *ptr = strstr(str, word);
    while(ptr != NULL) {
        count++;
        ptr = strstr(ptr + 1, word);
    }
    return count;
}
//Function to remove punctuations from a word
void removePunctuations(char *word) {
    int i, j = 0;
    for(i = 0; word[i] != '\0'; i++) {
        if(isalpha(word[i])) {
            word[j++] = tolower(word[i]);
        }
    }
    word[j] = '\0';
}
int main()
{
    char str[MAX_WORD_LENGTH], word[MAX_WORD_LENGTH];
    printf("Enter a sentence: ");
    fgets(str, MAX_WORD_LENGTH, stdin);
    printf("Enter the word to count frequency for: ");
    scanf("%s", word);
    removePunctuations(word);
    removePunctuations(str);
    int frequency = countFrequency(word, str);
    printf("'%s' appears %d times in '%s'\n", word, frequency, str);
    return 0;
}