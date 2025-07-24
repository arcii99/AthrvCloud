//FormAI DATASET v1.0 Category: Binary search trees ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct node* insert(struct node* root, int val){
    if(root == NULL){
        return createNode(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}
struct node* search(struct node* root, int val){
    if(root == NULL || root->data == val){
        return root;
    }
    else if(val < root->data){
        return search(root->left, val);
    }
    else{
        return search(root->right, val);
    }
}
struct node* minValueNode(struct node* node){
    struct node* curr = node;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}
struct node* deleteNode(struct node* root, int val){
    if(root == NULL){
        return root;
    }
    if(val < root->data){
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->data){
        root->right = deleteNode(root->right, val);
    }
    else{
        if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorderTraversal(struct node* root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
int main(){
    struct node* root = NULL;
    int choice, val;
    printf("Welcome to the Binary Search Tree program!\n\n");
    while(1){
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Search element\n");
        printf("4. Traverse tree\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter the element to be inserted: ");
                    scanf("%d", &val);
                    root = insert(root, val);
                    printf("Element %d inserted successfully.\n\n", val);
                    break;
            case 2: printf("Enter the element to be deleted: ");
                    scanf("%d", &val);
                    if(search(root, val) != NULL){
                        root = deleteNode(root, val);
                        printf("Element %d deleted successfully.\n\n", val);
                    }
                    else{
                        printf("Element not found!\n\n");
                    }
                    break;
            case 3: printf("Enter the element to be searched: ");
                    scanf("%d", &val);
                    if(search(root, val) != NULL){
                        printf("Element %d found!\n\n", val);
                    }
                    else{
                        printf("Element not found!\n\n");
                    }
                    break;
            case 4: printf("Inorder traversal of tree: ");
                    inorderTraversal(root);
                    printf("\n\n");
                    break;
            case 5: printf("Thank you for using the program!\n");
                    exit(0);
                    break;
            default:printf("Invalid choice! Please try again.\n\n");
        }
    }
    return 0;
}