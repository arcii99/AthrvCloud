//FormAI DATASET v1.0 Category: Mailing list manager ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

//Data structure to hold a mailing list node
typedef struct mailing_list_node {
    char* email; //Email address
    struct mailing_list_node* next; //Pointer to next mailing list node
} mailing_list_node;

//Function to add email to the mailing list
void add_email(mailing_list_node** head_ptr, char* email) {
    //Create new mailing list node
    mailing_list_node* new_email = (mailing_list_node*)malloc(sizeof(mailing_list_node));
    new_email->email = email;

    //Add new node to the head of the mailing list
    new_email->next = *head_ptr;
    *head_ptr = new_email;
}

//Function to print all emails in the mailing list
void print_mailing_list(mailing_list_node* head) {
    printf("Mailing List:\n");
    while(head != NULL) { //Iterate through all mailing list nodes
        printf("%s\n", head->email);
        head = head->next;
    }
}

int main() {
    mailing_list_node* my_mailing_list = NULL; //Pointer to the head of the mailing list

    //Add some emails to the mailing list
    add_email(&my_mailing_list, "johndoe@gmail.com");
    add_email(&my_mailing_list, "janedoe@yahoo.com");
    add_email(&my_mailing_list, "johnsmith@hotmail.com");

    //Print all emails in the mailing list
    print_mailing_list(my_mailing_list);

    return 0;
}