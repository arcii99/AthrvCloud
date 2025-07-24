//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char word[100];
    int count;
    struct node *next;
} Node;

Node *createNode(char *word) {
    Node *n = (Node*) malloc(sizeof(Node));
    strcpy(n->word, word);
    n->count = 1;
    n->next = NULL;
    return n;
}

void insert(Node **head, char *word) {
    Node *temp = *head;
    Node *prev = NULL;
    while(temp != NULL && strcmp(temp->word, word) < 0) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        Node *n = createNode(word);
        if(prev == NULL) {
            *head = n;
        } else {
            prev->next = n;
        }
    } else if(strcmp(temp->word, word) == 0) {
        temp->count += 1;
    } else {
        Node *n = createNode(word);
        if(prev == NULL) {
            *head = n;
        } else {
            prev->next = n;
        }
        n->next = temp;
    }
}

void printList(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        printf("Word: %s, Count: %d\n", temp->word, temp->count);
        temp = temp->next;
    }
}

void freeList(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        Node *prev = temp;
        temp = temp->next;
        free(prev);
    }
}

int main() {
    char str[1000];
    Node *head = NULL;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    char *token = strtok(str, " .,\n");
    while(token != NULL) {
        insert(&head, token);
        token = strtok(NULL, " .,\n");
    }
    printf("\nWord frequency:\n");
    printList(head);
    freeList(head);
    return 0;
}