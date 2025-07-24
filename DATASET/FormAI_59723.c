//FormAI DATASET v1.0 Category: Data structures visualization ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

// Structure definition of node
struct node{
    int info;
    struct node *next;
};

// Function to create node and return the pointer
struct node *createNode(int data){
    struct node *new_node= (struct node *)malloc(sizeof(struct node)); // allocate memory
    new_node->info= data;
    new_node->next= NULL;
    return new_node;
}

// Traverse and display list
void display(struct node *head){
    struct node *ptr= head;
    while(ptr!=NULL){
        printf("%d -> ",ptr->info);
        ptr= ptr->next;
    }
    printf("NULL");
}

// Create and display linked list
void createLinkedList(int arr[], int n){
    struct node *head= createNode(arr[0]); // Create head node
    struct node *tail= head;
    for(int i=1;i<n;i++){
        tail->next= createNode(arr[i]); // create new node and link
        tail= tail->next; // update tail
    }
    display(head); // Display the created linked list
}

int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    createLinkedList(arr,n);
    return 0;
}