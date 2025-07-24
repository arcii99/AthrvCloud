//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: peaceful
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void countWords(char *);
void printWordFrequency();

int main(){
    char text[500];
    printf("Welcome to the Word Frequency Counter!\n\n");
    printf("Enter your text (up to 500 characters):\n");
    fgets(text, 500, stdin);
    printf("\n");
    countWords(text);
    printWordFrequency();
    return 0;
}

struct wordNode {
    char *word;
    int frequency;
    struct wordNode *next;
};

struct wordNode *wordList = NULL;

void countWords(char *text){
    char *token;
    char *delim = " .,?!";
    token = strtok(text, delim);
    while(token != NULL) {
        struct wordNode *temp = wordList;
        while(temp != NULL) {
            if(strcmp(temp->word, token) == 0) {
                temp->frequency++;
                break;
            }
            temp = temp->next;
        }
        if(temp == NULL) {
            struct wordNode *newNode;
            newNode = (struct wordNode *)malloc(sizeof(struct wordNode));
            newNode->word = strdup(token);
            newNode->frequency = 1;
            newNode->next = wordList;
            wordList = newNode;
        }
        token = strtok(NULL, delim);
    }
}

void printWordFrequency(){
    struct wordNode *temp = wordList;
    printf("\nWord Frequency Count:\n\n");
    while(temp != NULL) {
        printf("%s: %d\n", temp->word, temp->frequency);
        temp = temp->next;
    }
}