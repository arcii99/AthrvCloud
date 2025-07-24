//FormAI DATASET v1.0 Category: Spell checking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//struct for linked list
struct node {
    char word[50];
    int count;
    struct node *next;
};
typedef struct node Node;

//function prototypes
Node* createNode(char* word);
void printList(Node* head);
void addWord(Node** head, char* word);

int main() {

    Node *head = NULL;

    //sample text to check
    char* text = "Thare is some text with speling errors and other mstakes. Thare are also som wyrds that are used incorrectly. Lets see how well this program relieses on catchin errors!";

    //splitting text into tokens
    char* token = strtok(text, " ,.!?");
    while(token) {

        //removing punctuation and converting to lowercase
        int length = strlen(token);
        if(ispunct(token[length-1])) {
            token[length-1] = '\0';
        }
        for(int i=0; i<length; i++) {
            token[i] = tolower(token[i]);
        }

        //checking if word exists in linked list and adding if not
        Node* current = head;
        while(current) {
            if(strcmp(current->word, token) == 0) {
                current->count++;
                break;
            }
            current = current->next;
        }
        if(!current) {
            addWord(&head, token);
        }

        //getting next token
        token = strtok(NULL, " ,.!?");
    }

    //printing the linked list
    printList(head);

    return 0;
}

//function to create a new node
Node* createNode(char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

//function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while(current) {
        printf("%s - %d\n", current->word, current->count);
        current = current->next;
    }
}

//function to add a word to the linked list
void addWord(Node** head, char* word) {
    Node* newNode = createNode(word);
    if(!(*head)) {
        *head = newNode;
    }
    else {
        Node* current = *head;
        while(current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}