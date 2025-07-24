//FormAI DATASET v1.0 Category: Mailing list manager ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Headers
void addEmail(char email[], char *list[]);
void removeEmail(char email[], char *list[]);
void printList(char *list[]);

int main(){
    // Welcome message
    printf("Greetings from the Mailing List Manager!\n");

    // Creating the mailing list
    char *list[50];
    for(int i=0; i<50; i++){
        list[i] = NULL;
    }

    // Random initialization
    srand(time(0));
    int random;

    // Initializing variables
    char email[30];
    char choice;

    // Program loop
    do{
        printf("\nChoose an option:\n");
        printf("1. Add email to the list\n");
        printf("2. Remove email from the list\n");
        printf("3. Print the full list\n");
        printf("4. Exit Mailing List Manager\n");
        scanf(" %c", &choice);

        switch(choice){
            case '1':
                printf("Enter the email address: ");
                scanf("%s", email);
                addEmail(email, list);
                printf("%s has been added to the list!\n", email);
                break;

            case '2':
                if(list[0] == NULL){
                    printf("The mailing list is empty!\n");
                    break;
                }
                random = rand() % 50;
                removeEmail(list[random], list);
                printf("%s has been removed from the list!\n", list[random]);
                break;

            case '3':
                printList(list);
                break;

            case '4':
                printf("Thank you for using Mailing List Manager!\n");
                break;

            default:
                printf("That is not a valid option!\n");
                break;
        }

    }while(choice != '4');

    return 0;
}


/*
    Adds an email address to the mailing list
*/
void addEmail(char email[], char *list[]){
    for(int i=0; i<50; i++){
        if(list[i] == NULL){
            list[i] = malloc(sizeof(email));
            list[i] = email;
            return;
        }
    }
}


/*
    Removes an email address from the mailing list
*/
void removeEmail(char email[], char *list[]){
    for(int i=0; i<50; i++){
        if(list[i] != NULL && list[i] == email){
            list[i] = NULL;
            return;
        }
    }
}


/*
    Prints the full mailing list
*/
void printList(char *list[]){
    printf("\nThe mailing list:\n");
    for(int i=0; i<50; i++){
        if(list[i] != NULL){
            printf("\t%s\n", list[i]);
        }
    }
}