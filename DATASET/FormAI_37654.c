//FormAI DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
// Linked List Structure
struct account {
    int accno;
    char name[20];
    float balance;
    struct account* next;
};

// Global Head node 
struct account* head = NULL;

// Function to create new account 
struct account* create_account(int accno, char name[], float balance) {
    struct account* new_acc = (struct account*)malloc(sizeof(struct account));
    new_acc->accno = accno;
    strcpy(new_acc->name, name);
    new_acc->balance = balance;
    new_acc->next = NULL;
    return new_acc;
}

// Function to insert new account to the list
void insert_account(int accno, char name[], float balance) {
    struct account* new_acc = create_account(accno, name, balance);
    if(head == NULL){
        head = new_acc;
    }else{
        struct account* curr = head;
        while(curr->next!=NULL)
            curr = curr->next;
        curr->next=new_acc;
    }
    printf("\nAccount created Successfully!\n");
}

// Function to delete an account
void delete_account(int accno) {
    if(head==NULL){
        printf("\nNo accounts found in the system!\n");
    }else{
        struct account* curr = head;
        struct account* prev = NULL;
        while(curr->accno!=accno){
            prev = curr;
            curr = curr->next;
        }
        if(curr==NULL){
            printf("\nAccount does not exists!\n");
        }else{
            if(prev==NULL){
                head = head->next;
            }else{
                prev->next = curr->next;
            }
            free(curr);
            printf("\nAccount Deleted Successfully!\n");
        }
    }
}

// Function to display the accounts
void display_account() {
    if(head==NULL){
        printf("\nNo accounts found in the system!\n");
    }else{
        struct account* curr = head;
        printf("\nAccount No.\tName\tBalance\n");
        while(curr!=NULL){
            printf("%d\t\t%s\t%.2f\n", curr->accno, curr->name, curr->balance);
            curr = curr->next;
        }
    }
}

// Main Function
int main(){
    int choice;
    do{
        printf("\nWelcome to Banking Record System\n");
        printf("\n*********************************\n");
        printf("\n1. Create Account\n");
        printf("2. Delete Account\n");
        printf("3. Display Accounts\n");
        printf("4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                int accno;
                char name[20];
                float balance;
                printf("\nEnter Account No.: ");
                scanf("%d", &accno);
                printf("Enter Name: ");
                fflush(stdin);
                gets(name);
                printf("Enter Balance: ");
                scanf("%f", &balance);
                insert_account(accno, name, balance);
                break;
            case 2:
                printf("\nEnter Account No. to Delete: ");
                scanf("%d", &accno);
                delete_account(accno);
                break;
            case 3:
                display_account();
                break;
            case 4:
                printf("\nThank You, have a nice day!\n");
                break;
            default:
                printf("\nInvalid choice, please try again!\n");
        }
    }while(choice!=4);
    return 0;
}