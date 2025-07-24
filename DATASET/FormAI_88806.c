//FormAI DATASET v1.0 Category: Binary search trees ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int number; 
    struct node* parent; 
    struct node* left; 
    struct node* right; 
};

struct node* root = NULL;

struct node* create_node(int value) 
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->number = value;
    temp->parent = NULL;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert_node(int value) 
{
    struct node *temp = root, *new_node = create_node(value);

    if (!temp)  // for first node
    {
        root = new_node;
        return;
    }

    while (1) 
    {
        if (temp->number > value) 
        {
            if (temp->left == NULL) 
            {
                temp->left = new_node;
                new_node->parent = temp;
                break;
            } 
            else 
            {
                temp = temp->left;
            }
        } 
        else 
        {
            if (temp->right == NULL) 
            {
                temp->right = new_node;
                new_node->parent = temp;
                break;
            } 
            else 
            {
                temp = temp->right;
            }
        }
    }
}

void in_order_print(struct node* current)
{
    if (current == NULL)
    {
        return;
    }
    in_order_print(current->left);
    printf("%d, ", current->number);
    in_order_print(current->right);
}

int main()
{
    insert_node(10);
    insert_node(6);
    insert_node(14);
    insert_node(5);
    insert_node(8);
    insert_node(11);
    insert_node(18);

    printf("In order traversal of BST: ");
    in_order_print(root);

    return 0;
}