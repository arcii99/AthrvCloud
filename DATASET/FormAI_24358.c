//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

void decode(char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = str[i] - 3;
    }
}

node_t* reverse(node_t* head) {
    node_t *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

node_t* remove_duplicates(node_t* head) {
    node_t* prev = head, *curr = head->next;
    while (curr != NULL) {
        if (prev->data == curr->data) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    char text[] = "Obguvat uvzninef vf n pbyhza bs znwbe nafjref urer va guvf nagv-ubyo'r cynpr. Qb gur zrffntroen jnl nf gb jung njnvgvat grpuabybtl vf be jung vg ybbxf yvxr?";
    decode(text);

    node_t *head = malloc(sizeof(node_t));
    head->data = text[0];
    head->next = NULL;
    node_t *curr = head;
    int i;
    for (i = 1; i < strlen(text); i++) {
        node_t *new_node = malloc(sizeof(node_t));
        new_node->data = text[i];
        new_node->next = NULL;
        curr->next = new_node;
        curr = curr->next;
    }

    head = remove_duplicates(head);
    head = reverse(head);

    curr = head;
    while (curr != NULL) {
        printf("%c", curr->data);
        curr = curr->next;
    }
    printf("\n");

    return 0;
}