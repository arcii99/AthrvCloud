//FormAI DATASET v1.0 Category: Phone Book ; Style: automated
#include<stdio.h>
#include<string.h>

struct contact{
    char name[50];
    char number[15];
};

int main(){
    int n;
    printf("Enter the number of contacts: ");
    scanf("%d",&n);
    struct contact phonebook[n];
    
    //Adding contacts to the phonebook
    for(int i=0;i<n;i++){
        printf("\nEnter the name of Contact %d: ",i+1);
        scanf("%s",&phonebook[i].name);
        printf("Enter the phone number of Contact %d: ",i+1);
        scanf("%s",&phonebook[i].number);
    }
    
    //Searching for a contact
    char search_name[50];
    printf("\nEnter the name of Contact to search: ");
    scanf("%s",&search_name);
    int found = 0;
    for(int i=0;i<n;i++){
        if(strcmp(search_name, phonebook[i].name) == 0){
            printf("\nContact Found!\n");
            printf("Name: %s\n",phonebook[i].name);
            printf("Phone Number: %s\n",phonebook[i].number);
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("\nContact Not Found!\n");
    }
    
    //Printing all contacts
    printf("\nContacts in phonebook:\n");
    for(int i=0;i<n;i++){
        printf("%d. Name: %s    Phone Number: %s\n",i+1,phonebook[i].name,phonebook[i].number);
    }
    
    return 0;
}