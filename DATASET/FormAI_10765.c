//FormAI DATASET v1.0 Category: Text Summarizer ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 1000
#define MAX_SENTENCES 50
#define MAX_WORDS 50

void remove_punctuation(char* text) {    // function to remove punctuations
    int i, len;
    len = strlen(text);
    for(i=0; i<len; i++) {
        if(!((text[i]>='a' && text[i]<='z') || (text[i]>='A' && text[i]<='Z') || (text[i]==' '))) {
            text[i]=' ';
        }
    }
}

void get_words(char* text, char words[][MAX_LEN]) {   // function to get words from text
    char* token = strtok(text, " ");
    int i = 0;
    while(token!=NULL) {
        strcpy(words[i], token);
        i++;
        token = strtok(NULL, " ");
    }
}

void remove_stop_words(char words[][MAX_LEN], int* n) {   // function to remove stop words
    char* stop_words[] = {"a", "an", "and", "are", "as", "at", "be", "but", "by", "for", "if", "in", "into", "is", "it", "no", "not", "of",
                        "on", "or", "such", "that", "the", "their", "then", "there", "these", "they", "this", "to", "was", "will", "with"};
    int i, j, k;
    for(i=0; i<*n; ) {
        k=0;
        for(j=0; j<32; j++) {
            if(strcmp(words[i], stop_words[j])==0) {
                k=1;
                break;
            }
        }
        if(k) {
            for(;i<*n-1; i++) {
                strcpy(words[i], words[i+1]);
            }
            (*n)--;
        }
        else {
            i++;
        }
    }
}

void summary(char words[][MAX_LEN], int n, int num_sentences) {  // function to generate summary
    char sentences[MAX_SENTENCES][MAX_LEN] = {0};
    int i, j, k, len, count[MAX_SENTENCES] = {0};
    for(i=0; i<n; i++) {
        if(words[i][strlen(words[i])-1]=='.' || words[i][strlen(words[i])-1]=='?' || words[i][strlen(words[i])-1]=='!') {
            k = i;
            len = strlen(words[i]);
            while(len > 1 && (words[i][len-1]<'0' || words[i][len-1]>'9')) { // To remove cases like Mr. and Mrs.
                len--;
            }
            while(k>0 && count[k-1]==0) {   // To include all sentences in the text
                k--;
            }
            strncpy(sentences[k], words[k], strlen(words[k])-len+1);
            count[k]++;
        }
    }
    int total_sentences = 0, max = 0, max_index = 0;
    for(i=0; i<MAX_SENTENCES; i++) {  // Find the top sentences and print them
        max = 0;
        for(j=0; j<n; j++) {
            if(count[j]>max) {
                max = count[j];
                max_index = j;
            }
        }
        if(max > 0) {
            printf("%s\n", sentences[max_index]);
            total_sentences++;
        }
        count[max_index] = 0;
        if(total_sentences>=num_sentences) {
            break;
        }
    }
}

int main() {    // main function to get input and call other functions
    char text[MAX_LEN];
    printf("Enter the text to summarize (maximum %d characters):\n", MAX_LEN);
    fgets(text, MAX_LEN, stdin);
    remove_punctuation(text);
    char words[MAX_WORDS][MAX_LEN] = {0};
    int n;
    get_words(text, words);
    n = sizeof(words)/sizeof(words[0]);
    remove_stop_words(words, &n);
    int num_sentences;
    printf("Enter the number of sentences required in the summary:\n");
    scanf("%d", &num_sentences);
    getchar();
    printf("Summary:\n");
    summary(words, n, num_sentences);
    return 0;
}