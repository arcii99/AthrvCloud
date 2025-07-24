//FormAI DATASET v1.0 Category: Binary search trees ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

struct tree_node{
    int data;
    struct tree_node *left_child;
    struct tree_node *right_child;
};

void bst_insert(struct tree_node **head, int num){
    if(*head == NULL){
        struct tree_node *new_node = (struct tree_node*)malloc(sizeof(struct tree_node));
        new_node->data = num;
        new_node->left_child = NULL;
        new_node->right_child = NULL;
        *head = new_node;
        return;
    }
    if(num<=(*head)->data){
        bst_insert(&((*head)->left_child),num);
    }else{
        bst_insert(&((*head)->right_child),num);
    }
}

void bst_inorder(struct tree_node *head){
    if(head==NULL){
        return;
    }
    bst_inorder(head->left_child);
    printf(" %d ",head->data);
    bst_inorder(head->right_child);
}

void main(){

    struct tree_node *head = NULL;
    int n,i,num;
    printf("Enter number of nodes:\n");
    scanf("%d",&n);
    printf("Enter %d nodes:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        bst_insert(&head,num);
    }
    printf("Binary search tree is: \n");
    bst_inorder(head);
}