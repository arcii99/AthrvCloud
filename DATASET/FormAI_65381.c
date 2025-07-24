//FormAI DATASET v1.0 Category: Text Summarizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOC_SIZE 10000
#define MAX_SUMMARY_SIZE 500

// Function to calculate the frequency of each word in the document
int calcFrequency(char *doc, char *word, int startIndex, int *endIndex) {
    int count = 0, len = strlen(doc), wordLen = strlen(word);
    char temp[MAX_DOC_SIZE];

    // Copy the section of document where word needs to be searched
    strncpy(temp, doc+startIndex, len-startIndex);
    
    // Search for the word in the section
    char *ptr = strstr(temp, word);
    while(ptr != NULL) {
        count++;
        ptr = strstr(ptr+wordLen, word);
    }
    
    // Update the endIndex with the end location of the searched section
    *endIndex = startIndex + strlen(temp);

    return count;
}

// Function to get the words from the document
int getWords(char *doc, char **words) {
    int count = 0;
    char *ptr = strtok(doc, " ");

    while(ptr != NULL) {
        // Remove punctuations from the word
        int len = strlen(ptr);
        if(ptr[len-1] == ',' || ptr[len-1] == '.') {
            ptr[len-1] = '\0';
        }

        // Add the word to the list of words
        words[count] = ptr;
        count++;
        ptr = strtok(NULL, " ");
    }

    return count;
}

// Function to get the maximum frequency of a word from the list of words
int getMaxFrequency(char **words, int numWords) {
    int max = 0;

    for(int i=0; i<numWords; i++) {
        int count = 1;
        for(int j=i+1; j<numWords; j++) {
            if(strcmp(words[i], words[j]) == 0) {
                count++;
            }
        }
        if(count > max) {
            max = count;
        }
    }

    return max;
}

// Function to get the summary of the document
char *getSummary(char *doc, int numSentences) {
    char *summary = (char *)malloc(sizeof(char) * MAX_SUMMARY_SIZE);
    char *ptr = strtok(doc, ".");
    int numWordsInSentences[numSentences];
    char *words[numWordsInSentences[numSentences]];
    int count = 0;

    // Get the number of words in each sentence and populate the list of words
    while(ptr != NULL) {
        int endIndex;
        numWordsInSentences[count] = getWords(ptr, words);
        count++;
        ptr = strtok(NULL, ".");
    }

    int maxFrequency = getMaxFrequency(words, numWordsInSentences[0]);
    int index = 0;

    // Select the most relevant sentence from the document for the summary
    for(int i=0; i<count; i++) {
        int startIndex = (i > 0)?(strlen(summary)+1):0, endIndex;
        int frequency = calcFrequency(doc, words[index], startIndex, &endIndex);

        if(frequency > maxFrequency) {
            maxFrequency = frequency;
            index = i;
        }
    }

    // Construct the summary from the most relevant sentences of the document
    for(int i=0; i<numSentences; i++) {
        strncat(summary, strtok(doc, "."), MAX_SUMMARY_SIZE-strlen(summary));
        if(i < (numSentences-1)) {
            strcat(summary, ".");
        }
        ptr = strtok(NULL, ".");
    }

    // Return the summary
    return summary;
}

int main() {
    char doc[MAX_DOC_SIZE] = "Natural language processing (NLP) is a subfield of linguistics, computer science, and artificial intelligence concerned with the interactions between computers and human language, in particular how to program computers to process and analyze large amounts of natural language data.\nThis interdisciplinary field includes computer science, mathematics, statistics, and engineering.\nAs humans, we are used to communicating with each other using natural language. We speak and listen, write and read, transfer information to other people. Computers, however, cannot handle human communication unless we provide them with a way to interpret and understand what we are saying (or writing).\nIn other words, we need to create computer programs that can process natural language before we can use computers to analyze, interpret, translate, and generate human language.\n";

    char *summary = getSummary(doc, 3);

    printf("Summary:\n%s\n", summary);

    return 0;
}