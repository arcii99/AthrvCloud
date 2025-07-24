//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    printf("Oh data structures, thou art the only way");
    printf("To visualize code in an elegant display.\n");
    printf("In C, a node thou can define\n");
    printf("Through which linked lists we can assign.\n");
    printf("For example, let's take Romeo and Juliet\n");
    printf("Their love and fate, we shall conflate.\n");
    printf("Each character as a node, we define\n");
    printf("And for their love, we'll assign and align.\n");
    
    struct node *romeo = (struct node *)malloc(sizeof(struct node));
    romeo->data = 1;
    romeo->next = NULL;
    struct node *juliet = (struct node *)malloc(sizeof(struct node));
    juliet->data = 2;
    juliet->next = NULL;

    // Romeo and Juliet meet
    romeo->next = juliet;
    juliet->next = NULL;

    printf("With a linked list, we can see\n");
    printf("Each lover's fate, and who comes after thee.\n");
    printf("Romeo and Juliet shall not be alone\n");
    printf("For in linked lists, their love shall be shown.\n");

    free(romeo);
    free(juliet);

    return 0;
}