//FormAI DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <string.h>

// function to remove punctuation and convert all characters to lowercase
void cleanString(char* str) {
    int len = strlen(str);

    // remove punctuation
    for(int i=0; i<len; i++) {
        if(str[i] == '.' || str[i] == '?' || str[i] == '!') {
            str[i] = ' ';
        }
    }

    // convert to lowercase
    for(int i=0; i<len; i++) {
        str[i] = tolower(str[i]);
    }
}

// utility function to calculate the number of words in a string
int countWords(char* str) {
    int count = 0;
    int flag = 0;

    for(int i=0; str[i]!='\0'; i++) {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            flag = 0;
        }
        else {
            if(flag == 0) {
                count++;
                flag = 1;
            }
        }
    }

    return count;
}

// function to find the frequency of each word in a string
void findFrequency(char* str, char words[][100], int frequency[], int count) {
    int len = strlen(str);
    char word[100];
    int index = 0;
    int wordCount = 0;

    // loop through each character and extract each word
    for(int i=0; i<len; i++) {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            word[index] = '\0';
            index = 0;

            if(strlen(word) > 0) {
                // check if word is already in the list of unique words
                int flag = 0;
                for(int j=0; j<wordCount; j++) {
                    if(strcmp(words[j], word) == 0) {
                        frequency[j]++;
                        flag = 1;
                        break;
                    }
                }

                // if word is not in the list of unique words, add it and set its frequency to 1
                if(flag == 0) {
                    strcpy(words[wordCount], word);
                    frequency[wordCount] = 1;
                    wordCount++;
                }
            }
        }
        else {
            word[index] = str[i];
            index++;
        }
    }

    // handle the last word in the string
    if(index > 0) {
        word[index] = '\0';

        if(strlen(word) > 0) {
            // check if word is already in the list of unique words
            int flag = 0;
            for(int j=0; j<wordCount; j++) {
                if(strcmp(words[j], word) == 0) {
                    frequency[j]++;
                    flag = 1;
                    break;
                }
            }

            // if word is not in the list of unique words, add it and set its frequency to 1
            if(flag == 0) {
                strcpy(words[wordCount], word);
                frequency[wordCount] = 1;
                wordCount++;
            }
        }
    }
}

// function to find the index of the most frequent word
int findMostFrequentWord(char words[][100], int frequency[], int count) {
    int maxIndex = 0;
    int maxFrequency = frequency[0];

    for(int i=1; i<count; i++) {
        if(frequency[i] > maxFrequency) {
            maxIndex = i;
            maxFrequency = frequency[i];
        }
    }

    return maxIndex;
}

// main function
int main() {
    char input[10000];
    char sentences[100][1000];
    char words[1000][100];
    int frequency[1000];
    int sentenceCount = 0;

    printf("Enter the text to summarize:\n");
    fgets(input, 10000, stdin);

    // clean the input string
    cleanString(input);

    // count the number of sentences in the input string and store them in an array
    int len = strlen(input);
    int index = 0;
    for(int i=0; i<len; i++) {
        if(input[i] == '.' || input[i] == '?' || input[i] == '!') {
            sentences[sentenceCount][index] = input[i];
            sentences[sentenceCount][index+1] = '\0';
            sentenceCount++;
            index = 0;
        }
        else {
            sentences[sentenceCount][index] = input[i];
            index++;
        }
    }

    // count the number of words in each sentence and find the most frequent word in the entire string
    int maxIndex = 0;
    int maxFrequency = 0;

    for(int i=0; i<sentenceCount; i++) {
        int wordCount = countWords(sentences[i]);
        findFrequency(sentences[i], words, frequency, wordCount);

        int sentenceMaxIndex = findMostFrequentWord(words, frequency, wordCount);
        int sentenceMaxFrequency = frequency[sentenceMaxIndex];

        if(sentenceMaxFrequency > maxFrequency) {
            maxIndex = i;
            maxFrequency = sentenceMaxFrequency;
        }
    }

    // print the summary
    printf("\nSummary:\n%s\n", sentences[maxIndex]);

    return 0;
}