//FormAI DATASET v1.0 Category: Word Count Tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

typedef struct node {
    char word[MAX_WORD_LENGTH];
    int count;
    struct node* next;
} Node;

void insert(Node** root, char* word) {
    if (*root == NULL) {
        *root = (Node*) malloc(sizeof(Node));
        strcpy((*root)->word, word);
        (*root)->count = 1;
        (*root)->next = NULL;
        return;
    }
    Node* current = *root;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }
    current = *root;
    while (current->next != NULL) {
        current = current->next;
    }
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->next = NULL;
    current->next = newNode;
}

void display(Node* root) {
    printf("%-20s | %s\n", "Word", "Count");
    printf("---------------------\n");
    while (root != NULL) {
        printf("%-20s | %d\n", root->word, root->count);
        root = root->next;
    }
}

void split(char* line, Node** root) {
    char *token = strtok(line, " .,?-!");
    while (token != NULL) {
        char word[MAX_WORD_LENGTH];
        int index = 0;
        for (int i = 0; i < strlen(token); i++) {
            if (isalpha(token[i])) {
                word[index++] = tolower(token[i]);
            }
        }
        word[index] = '\0';
        if (strlen(word) > 0) {
            insert(root, word);
        }
        token = strtok(NULL, " .,?-!");
    }
}

int main() {
    Node* root = NULL;
    char line[100];
    while(1) {
        printf("Enter a sentence (type exit to stop): ");
        fgets(line, 100, stdin);
        line[strcspn(line, "\n")] = 0; // remove trailing newline
        if (strcmp(line, "exit") == 0) {
            break;
        }
        split(line, &root);
    }
    display(root);
    return 0;
}