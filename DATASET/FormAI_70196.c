//FormAI DATASET v1.0 Category: Data structures visualization ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node {
    int value;
    struct Node* next;
};

void printList(struct Node* head) {
    struct Node* current = head;
    printf("Start -> ");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    srand(time(NULL));
    struct Node* head = malloc(sizeof(struct Node));
    head->value = rand()%100;
    head->next = NULL;
    struct Node* current = head;
    
    int i;
    for (i = 0; i < 7; i++) {
        current->next = malloc(sizeof(struct Node));
        current = current->next;
        current->value = rand()%100;
        current->next = NULL;
    }
    
    printList(head);
    
    return 0;
}