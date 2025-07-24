//FormAI DATASET v1.0 Category: Data structures visualization ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

struct Node {
    int value;
    struct Node* next;
};

typedef struct Node Node;

Node* add_node(Node* head, int value)
{
    if (head == NULL)
    {
        head = (Node*)malloc(sizeof(Node));
        head->value = value;
        head->next = NULL;
        return head;
    }
    else
    {
        Node* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = (Node*)malloc(sizeof(Node));
        current->next->value = value;
        current->next->next = NULL;
        return head;
    }
}

void print_list(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Node* list[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++)
    {
        list[i] = NULL;
    }
    list[0] = add_node(list[0], 1);
    list[0] = add_node(list[0], 2);
    list[1] = add_node(list[1], 3);
    list[1] = add_node(list[1], 4);
    list[2] = add_node(list[2], 5);
    list[3] = add_node(list[3], 6);
    list[4] = add_node(list[4], 7);
    list[4] = add_node(list[4], 8);
    list[5] = add_node(list[5], 9);
    list[5] = add_node(list[5], 10);

    for (int i = 0; i < MAX_NODES; i++)
    {
        printf("List %d: ", i + 1);
        print_list(list[i]);
    }

    return 0;
}