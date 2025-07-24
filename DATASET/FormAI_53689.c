//FormAI DATASET v1.0 Category: Memory management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define PUZZLE_SEC (char)60

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* head = NULL;
int nodeCount = 0;

void addNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }else{
        Node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    nodeCount++;
}

void removeNode(int index){
    if(index < 0 || index >= nodeCount){
        printf("Invalid index\n");
        return;
    }
    int i = 0;
    Node* current = head;
    Node* previous = NULL;
    while(i < index && current != NULL){
        previous = current;
        current = current->next;
        i++;
    }
    if(previous == NULL){
        head = current->next;
    }else{
        previous->next = current->next;
    }
    free(current);
    nodeCount--;
}

void printList(){
    Node* current = head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void solvePuzzle(){
    printf("Welcome to the Memory Management Puzzle\n");
    printf("The objective is to free all memory blocks within %d seconds\n", PUZZLE_SEC);
    printf("You can start by adding nodes using addNode() function\n");
    printf("Remember to remove the nodes after they are used using removeNode() function\n");
    printf("Good luck!\n\n");
    
    int input = 0;
    time_t startTime = time(NULL);
    while(difftime(time(NULL), startTime) < PUZZLE_SEC){
        printf("Nodes added: %d\t", nodeCount);
        printList();
        printf("Enter node data (0 to quit): ");
        scanf("%d", &input);
        if(input == 0){
            printf("Quitting...\n");
            break;
        }
        addNode(input);
    }
    printf("Time's up!\n");
    printf("Final node count: %d\n", nodeCount);
    Node* current = head;
    while(current != NULL){
        Node* temp = current->next;
        free(current);
        current = temp;
    }
}

int main(){
    solvePuzzle();
    return 0;
}