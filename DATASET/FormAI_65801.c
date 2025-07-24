//FormAI DATASET v1.0 Category: Spell checking ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 100

struct DictNode{
    char word[MAX_LENGTH];
    struct DictNode *next;
};

int hash(char* word){
    int sum = 0;
    for(int i=0;i<strlen(word);i++){
        sum += word[i];
    }
    return sum % 26;
}

struct DictNode* createDictNode(char* word){
    struct DictNode* newNode = (struct DictNode*)malloc(sizeof(struct DictNode));
    strcpy(newNode->word,word);
    newNode->next = NULL;
    return newNode;
}

void addToDict(struct DictNode* dict[], char* word){
    int index = hash(word);

    struct DictNode* currentNode = dict[index];
    struct DictNode* prevNode = NULL;

    while(currentNode != NULL){
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if(prevNode == NULL){
        dict[index] = createDictNode(word);
    }else{
        prevNode->next = createDictNode(word);
    }
}

void printDict(struct DictNode* dict[]){
    for(int i=0;i<26;i++){
        struct DictNode* currentNode = dict[i];
        printf("\n%d: ", i);
        while(currentNode != NULL){
            printf("%s ", currentNode->word);
            currentNode = currentNode->next;
        }
    }
}

int checkIfWordIsCorrect(struct DictNode* dict[], char* word){
    int index = hash(word);

    struct DictNode* currentNode = dict[index];

    while(currentNode != NULL){
        if(strcmp(currentNode->word,word)==0){
            return 1;
        }
        currentNode = currentNode->next;
    }

    return 0;
}

void spellCheckText(struct DictNode* dict[], char* text){
    char* word = strtok(text," ");

    while(word != NULL){
        if(!checkIfWordIsCorrect(dict,word)){
            printf("\n%s is misspelled!", word);
        }

        word = strtok(NULL," ");
    }
}

int main(){
    char dictWords[10][MAX_LENGTH] = {"apple", "banana", "carrot", "dog", "elephant", "fox", "grape", "horse", "ice cream", "juice"};

    struct DictNode* dict[26];

    for(int i=0;i<26;i++){
        dict[i] = NULL;
    }

    for(int i=0;i<10;i++){
        addToDict(dict,dictWords[i]);
    }

    printDict(dict);

    char text[MAX_LENGTH];
    printf("\nEnter the text to be spell checked: ");
    fgets(text,MAX_LENGTH,stdin);

    spellCheckText(dict,text);

    return 0;
}