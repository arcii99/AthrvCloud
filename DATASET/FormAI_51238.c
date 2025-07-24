//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// structure to store frequency of words
struct Node 
{
    char* word;
    int count;
    struct Node* next;
};

// function to create a new node
struct Node* newNode(char* word)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

// function to insert a new node into linked list
void insert(struct Node** head, char* word)
{
    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current != NULL && strcmp(word, current->word) > 0) 
    {
        prev = current;
        current = current->next;
    }
    if (current != NULL && strcmp(word, current->word) == 0) 
    {
        current->count++;
    } 
    else 
    {
        struct Node* new_node = newNode(word);
        if (prev == NULL) 
        {
            new_node->next = *head;
            *head = new_node;
        } 
        else 
        {
            new_node->next = current;
            prev->next = new_node;
        }
    }
}

// function to print linked list of word frequencies
void printList(struct Node* head)
{
    while (head != NULL)
    {
        printf("%s: %d\n", head->word, head->count);
        head = head->next;
    }
}

int main()
{
    char str[1000];
    printf("Enter a sentence (less than 1000 characters): ");
    fgets(str, 1000, stdin);
    char* word;
    struct Node* head = NULL;
    word = strtok(str, " ,.-\n\t");
    while (word != NULL)
    {
        for (int i = 0; i < strlen(word); i++)
        {
            word[i] = tolower(word[i]);
        }
        insert(&head, word);
        word = strtok(NULL, " ,.-\n\t");
    }
    printf("Word frequencies in the sentence:\n");
    printList(head);
    return 0;
}