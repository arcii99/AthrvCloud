//FormAI DATASET v1.0 Category: Mailing list manager ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 50
#define MAX_LENGTH 100

typedef struct Email {
    char address[MAX_LENGTH];
} Email;

typedef struct MailingList {
    Email emailList[MAX_EMAILS];
    int count;
} MailingList;

void printEmails(MailingList* list) {
    printf("Mailing List:\n");
    for(int i = 0; i < list->count; i++) {
        printf("%s\n", list->emailList[i].address);
    }
    printf("\n");
}

int addEmail(MailingList* list, char* address) {
    if(list->count == MAX_EMAILS) {
        printf("Mailing List is full! Cannot add email.\n");
        return 0;
    }
    if(strlen(address) >= MAX_LENGTH) {
        printf("Email address too long! Cannot add email.\n");
        return 0;
    }
    Email new_email;
    strcpy(new_email.address, address);
    list->emailList[list->count] = new_email;
    list->count++;
    printf("New email added! Total emails in mailing list: %d\n", list->count);
    return 1;
}

void removeEmail(MailingList* list, char* address) {
    for(int i = 0; i < list->count; i++) {
        if(strcmp(list->emailList[i].address, address) == 0) {
            for(int j = i; j < list->count - 1; j++) {
                list->emailList[j] = list->emailList[j+1];
            }
            list->count--;
            printf("Email removed! Total emails in mailing list: %d\n", list->count);
            return;
        }
    }
    printf("Email not found! Cannot remove email.\n");
}

int main() {
    MailingList myList;
    myList.count = 0;

    addEmail(&myList, "john.doe@example.com");
    addEmail(&myList, "jane.doe@example.com");
    addEmail(&myList, "bob.smith@example.com");
    
    printEmails(&myList);
    
    removeEmail(&myList, "jane.doe@example.com");
    
    printEmails(&myList);
    
    addEmail(&myList, "alice.jones@example.com");
    addEmail(&myList, "jim.brown@example.com");
    
    printEmails(&myList);
    
    return 0;
}