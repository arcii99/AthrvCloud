//FormAI DATASET v1.0 Category: Spell checking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100

// Function to check if a string is a valid word
int isWord(char* str){
    int i;
    for(i=0;str[i]!='\0';i++){
        if(!isalpha(str[i]))
            return 0;
    }
    return 1;
}

// Function to read input file and store words in an array
int readInputFile(char* filename, char** wordList, int maxWords){
    FILE* fp;
    char word[MAX_WORD_SIZE];
    int count = 0;

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Could not open file: %s\n", filename);
        exit(1);
    }

    while(fscanf(fp, "%s", word) != EOF){
        if(isWord(word) && count < maxWords){
            strcpy(wordList[count], word);
            count++;
        }
    }

    fclose(fp);

    return count;
}

// Function to read dictionary file and store words in an array
int readDictionaryFile(char* filename, char** dictList, int maxWords){
    FILE* fp;
    char word[MAX_WORD_SIZE];
    int count = 0;

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Could not open file: %s\n", filename);
        exit(1);
    }

    while(fscanf(fp, "%s", word) != EOF){
        if(isWord(word) && count < maxWords){
            strcpy(dictList[count], word);
            count++;
        }
    }

    fclose(fp);

    return count;
}

// Function to compare two strings ignoring case
int strcasecmp(const char *s1, const char *s2){
    while(*s1 != '\0' && *s2 != '\0'){
        if(tolower(*s1) != tolower(*s2)){
            return (tolower(*s1) - tolower(*s2));
        }
        s1++;
        s2++;
    }
    return (tolower(*s1) - tolower(*s2));
}

// Function to spell check a word and suggest corrections if needed
void spellcheck(char* word, char** dictList, int dictSize){
    int i, found = 0;
    char temp[MAX_WORD_SIZE];

    // Check if the word is in the dictionary
    for(i=0;i<dictSize;i++){
        if(strcasecmp(word, dictList[i]) == 0){
            found = 1;
            break;
        }
    }

    // If word is not in the dictionary, suggest corrections
    if(!found){
        printf("\nWord not found in dictionary: %s\n", word);
        printf("Possible corrections:\n");

        // Generate possible corrections by replacing each character in the word with alphabets (a-z)
        for(i=0;i<strlen(word);i++){
            char ch;
            int j;
            for(j=0; j<26; j++){
                strcpy(temp, word);
                ch = 'a' + j;
                temp[i] = ch;

                // Check if the modified word is in the dictionary
                for(int k=0;k<dictSize;k++){
                    if(strcasecmp(temp, dictList[k]) == 0){
                        printf("%s ", temp);
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
}

int main(){
    char* inputFilename = "input.txt";
    char* dictFilename = "dictionary.txt";
    char* wordList[MAX_WORD_SIZE];
    char* dictList[MAX_WORD_SIZE];
    int maxWords = MAX_WORD_SIZE;
    int wordCount, dictCount, i;

    // Allocate memory for word list and dictionary list
    for(i=0;i<maxWords;i++){
        wordList[i] = (char*)malloc(sizeof(char) * MAX_WORD_SIZE);
        dictList[i] = (char*)malloc(sizeof(char) * MAX_WORD_SIZE);
    }

    // Read input file and store words in an array
    wordCount = readInputFile(inputFilename, wordList, maxWords);

    // Read dictionary file and store words in an array
    dictCount = readDictionaryFile(dictFilename, dictList, maxWords);

    // Spell check each word in the input file
    for(i=0;i<wordCount;i++){
        spellcheck(wordList[i], dictList, dictCount);
    }

    // Free memory allocated for word list and dictionary list
    for(i=0;i<maxWords;i++){
        free(wordList[i]);
        free(dictList[i]);
    }

    return 0;
}