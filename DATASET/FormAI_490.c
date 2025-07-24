//FormAI DATASET v1.0 Category: Text Summarizer ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getFrequency(char* text, int* frequency, int* numWords) {
    char delimeters[] = " .,\n!?";
    char* word = strtok(text, delimeters);

    while(word != NULL) {
        (*numWords)++;
        for(int i=0;i<strlen(word);i++) {
            word[i] = tolower(word[i]);
        }
        frequency[word[0]-'a']++;
        word = strtok(NULL, delimeters);
    }
}

int countSentences(char* text) {
    int count=0;

    for(int i=0;i<strlen(text);i++) {
        if(text[i] == '.' || text[i] == '?' || text[i] == '!') {
            count++;
        }
    }
    return count;
}

float getScore(int* frequency, int* numWords, char* sentence) {
    char delimeters[] = " .,\n!?";
    char* word = strtok(sentence, delimeters);
    float score=0;
    while(word != NULL) {
        for(int i=0;i<strlen(word);i++) {
            word[i] = tolower(word[i]);
        }
        score += (float)frequency[word[0]-'a']/(float)*numWords;
        word = strtok(NULL, delimeters);
    }

    return score;
}

int main() {
    char text[] = "In C programming, text summarization can be done through various methods. One of the most popular method is to calculate the frequency of each word and then rate each sentence by the sum of it's word frequencies. Another method is to calculate the similarity between sentences based on the cosine similarity of their word frequencies. A good text summarizer must take into account the context of the document, and use advanced techniques like natural language processing and machine learning.";
    int frequency[26] = {0};
    int numWords = 0;
    getFrequency(text, frequency, &numWords);

    int numSentences = countSentences(text);
    char* sentences[numSentences];
    int sentenceScores[numSentences];

    char delimeters[] = ".?!";
    char* sentence = strtok(text, delimeters);
    int i=0;
    while(sentence != NULL) {
        sentences[i] = sentence;
        sentenceScores[i] = getScore(frequency, &numWords, sentence);
        sentence = strtok(NULL, delimeters);
        i++;
    }

    //Sort the sentences based on their score.highest score sentence comes first.
    for(int i=0;i<numSentences-1;i++) {
        for(int j=i+1;j<numSentences;j++) {
            if(sentenceScores[i] < sentenceScores[j]) {
                int tempScore = sentenceScores[i];
                sentenceScores[i] = sentenceScores[j];
                sentenceScores[j] = tempScore;

                char* tempSentence = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = tempSentence;
            }
        }
    }

    //Print top 3 sentences
    for(int i=0;i<3;i++) {
        printf("%s\n", sentences[i]);
    }

    return 0;
}