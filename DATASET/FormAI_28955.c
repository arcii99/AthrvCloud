//FormAI DATASET v1.0 Category: Text Summarizer ; Style: future-proof
#include<stdio.h>
#include<string.h>

// Structure to store the word and its frequency
struct Word {
    char word[20];
    int freq;
};

// Function to remove punctuation marks from the given word
void remove_punctuations(char *word) {
    int len = strlen(word);
    for(int i=0; i<len; i++) {
        if(word[i] == '.' || word[i] == ',' || word[i] == ';' || word[i] == ':' || word[i] == '?' || word[i] == '!') {
            for(int j=i; j<len-1; j++) {
                word[j] = word[j+1];
            }
            len--;
            i--;
        }
    }
}

// Function to check whether a given word is a stop word or not
int is_stopword(char *word) {
    char stop_words[10][20] = {"a", "an", "the", "in", "on", "above", "below", "under", "over", "through"};
    for(int i=0; i<10; i++) {
        if(strcmp(stop_words[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char input[1000], *word, *token;
    struct Word words[1000];
    int n = 0, flag;

    printf("Enter the text to be summarized:\n");
    fgets(input, 1000, stdin);

    // Convert the entire text to lowercase
    for(int i=0; i<strlen(input); i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') {
            input[i] += 32;
        }
    }

    // Split the text into words and count their frequencies
    word = strtok(input, " ");
    while(word != NULL) {
        flag = 0;
        remove_punctuations(word);
        if(is_stopword(word)) {
            word = strtok(NULL, " ");
            continue;
        }
        for(int i=0; i<n; i++) {
            if(strcmp(words[i].word, word) == 0) {
                words[i].freq++;
                flag = 1;
                break;
            }
        }
        if(!flag) {
            strcpy(words[n].word, word);
            words[n].freq = 1;
            n++;
        }
        word = strtok(NULL, " ");
    }

    // Sort the words in order of their frequency
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(words[i].freq < words[j].freq) {
                struct Word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print the summarized text with top 5 frequent words
    printf("\nSummarized Text:\n");
    word = strtok(input, " ");
    while(word != NULL) {
        flag = 0;
        for(int i=0; i<5; i++) {
            if(strcmp(words[i].word, word) == 0) {
                flag = 1;
                break;
            }
        }
        if(flag || n <= 5) {
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }

    return 0;
}