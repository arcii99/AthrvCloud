//FormAI DATASET v1.0 Category: Phone Book ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact{
    char name[50];
    char phone_number[15];
    char email[50];
};

int main(){
    int num_of_contacts;
    printf("Enter number of contacts: ");
    scanf("%d", &num_of_contacts);
    
    struct contact contacts[num_of_contacts];
    fflush(stdin);
    
    for(int i=0; i<num_of_contacts; i++){
        printf("\nEnter details of contact %d:\n", i+1);
        printf("Enter name: ");
        scanf("%[^\n]%*c", contacts[i].name);
        printf("Enter phone number: ");
        scanf("%s", contacts[i].phone_number);
        printf("Enter email: ");
        scanf("%s", contacts[i].email);
    }
    
    printf("\n\n======================================\n");
    printf("YOUR ROMANTIC PHONE BOOK\n");
    printf("======================================\n");
    
    printf("\tName\t\t|   Phone Number   |   Email\n");
    printf("-------------------------------------------------\n");
    
    for(int i=0; i<num_of_contacts; i++){
        printf("\t%-15s|   %-15s|   %-15s\n", contacts[i].name, contacts[i].phone_number, contacts[i].email);
    }
    
    printf("\n\nLove is in the air!");
    return 0;
}