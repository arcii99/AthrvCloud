//FormAI DATASET v1.0 Category: Mailing list manager ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LEN 50

typedef struct {
    char email[MAX_EMAIL_LEN];
} Email;

typedef struct {
    Email emails[MAX_EMAILS];
    int size;
} MailingList;

void addToList(MailingList *list, char *email) {
    int i;
    for(i=0; i<list->size; i++) {
        //Check if email is already in the list
        if(strcmp(list->emails[i].email,email)==0) {
            printf("Email already in list\n");
            return;
        }
    }
    //Email not in list, add to end of list
    strcpy(list->emails[list->size].email,email);
    list->size++;
    printf("Email added to list\n");
}

void removeFromList(MailingList *list, char *email) {
    int i;
    for(i=0; i<list->size; i++) {
        if(strcmp(list->emails[i].email,email)==0) {
            //Email found, remove from list
            int j;
            for(j=i; j<list->size-1; j++) {
                strcpy(list->emails[j].email,list->emails[j+1].email);
            }
            list->size--;
            printf("Email removed from list\n");
            return;
        }
    }
    //Email not found in list
    printf("Email not found in list\n");
}

void printList(MailingList *list) {
    printf("Mailing List:\n");
    int i;
    for(i=0; i<list->size; i++) {
        printf("%d. %s\n",i+1,list->emails[i].email);
    }
    printf("\n");
}

int main() {
    MailingList list;
    list.size = 0;
    int choice;
    char email[MAX_EMAIL_LEN];
    while(1) {
        printf("1. Add email to list\n");
        printf("2. Remove email from list\n");
        printf("3. Print mailing list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: 
                printf("Enter email: ");
                scanf("%s",email);
                addToList(&list,email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s",email);
                removeFromList(&list,email);
                break;
            case 3:
                printList(&list);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}