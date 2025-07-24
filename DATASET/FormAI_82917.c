//FormAI DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>

//Defining a structure 'Person' containing a person's name, phone number and address
struct Person {
    char name[50];
    long int phone;
    char address[50];
};

//Global variables
int n=0;
struct Person phonebook[100];

int main() {
    printf("Welcome to the Sherlock Holmes Phonebook!\n");
    printf("Please select an option:\n");
    printf("1. Add a person\n2. Search for a person\n3. Display all persons\n4. Exit program\n");

    int op;
    while(1) {
        printf("\nEnter your option here: ");
        scanf("%d", &op);

        switch(op) {
            case 1: 
                add_person(); 
                break;
            case 2: 
                search_person(); 
                break;
            case 3: 
                display_book(); 
                break;
            case 4: 
                printf("Thank you for using the Sherlock Holmes Phonebook.\n"); 
                return 0;
            default: 
                printf("Invalid option, please try again.\n");
        }
    }
}

//Function to add a person to the phonebook
void add_person() {
    printf("\nEnter person's name: ");
    scanf("%s", phonebook[n].name);
    printf("Enter person's phone number: ");
    scanf("%ld", &phonebook[n].phone);
    printf("Enter person's address: ");
    scanf("%s", phonebook[n].address);
    n++;
    printf("Person added to phonebook.\n");
}

//Function to search for a person in the phonebook
void search_person() {
    char name[50];
    printf("\nEnter person's name: ");
    scanf("%s", name);
    int found=0;
    for(int i=0;i<n;i++) {
        if(strcmp(name,phonebook[i].name)==0) {
            printf("Name: %s\nPhone Number: %ld\nAddress: %s\n",phonebook[i].name,phonebook[i].phone,phonebook[i].address);
            found=1;
            break;
        }
    }
    if(found==0) {
        printf("Person not found in phonebook.\n");
    }
}

//Function to display all persons in the phonebook
void display_book() {
    for(int i=0;i<n;i++) {
        printf("\nName: %s\nPhone Number: %ld\nAddress: %s\n",phonebook[i].name,phonebook[i].phone,phonebook[i].address);
    }
}