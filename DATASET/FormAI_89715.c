//FormAI DATASET v1.0 Category: Data structures visualization ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int value;
    struct node* next;
}node;

void print_linked_list(node* head) {
    node* curr = head;
    if (curr == NULL) {
        printf("Empty list\n");
        return;
    }
    while (curr->next != NULL) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("%d\n", curr->value);
}

int main()
{
    srand(time(NULL));
    node* head = NULL;
    for (int i = 0; i < 10; i++) {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->value = rand() % 10 + 1;
        new_node->next = head;
        head = new_node;
    }

    printf("Welcome to the post-apocalyptic world.\n");
    printf("In this world, the only way to survive is to find hidden treasures.\n");
    printf("You have stumbled upon a map which will lead you to the location of these treasures.\n");

    printf("\nThis is your map:\n\n");
    print_linked_list(head);
    printf("\nThe numbers indicate the distance from one location to another.\n");

    printf("\nBe careful, this world is full of dangers. You may encounter monsters, traps, and other obstacles.\n");
    printf("But with this map, you have a chance to find the treasures and save humanity.\n");

    return 0;
}