//FormAI DATASET v1.0 Category: Spell checking ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char* word;
    struct node* next;
} Node;

void insert(Node** headRef, char* data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->word = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

void checkSpelling(Node* head, char* input){
    int found = 0;
    char* word = strtok(input," ");
    while(word != NULL){
        found = 0;
        for(Node* ptr = head; ptr != NULL; ptr = ptr->next){
            if(strcmp(ptr->word, word) == 0){
                found = 1;
                break;
            }
        }
        if(!found){
            printf("'%s' is misspelled.\n", word);
        }
        word = strtok(NULL, " ");
    }
}

int main(){
    Node* head = NULL;
    insert(&head, "decentralized");
    insert(&head, "spell");
    insert(&head, "checking");
    insert(&head, "program");
    
    char input[100];
    printf("Enter your input string: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;

    checkSpelling(head, input);
    return 0;
}