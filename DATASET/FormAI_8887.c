//FormAI DATASET v1.0 Category: Mailing list manager ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Surrealist style Mailing list manager program

typedef struct member {
    char name[50];
    char email[50];
    struct member *next;
} Member;

Member *head = NULL;

Member* createMember(char name[], char email[]) {
    Member *newMember = (Member*) malloc(sizeof(Member));
    strcpy(newMember->name, name);
    strcpy(newMember->email, email);
    newMember->next = NULL;
    return newMember;
}

void addMember(char name[], char email[]) {
    Member *newMember = createMember(name, email);
    if (head == NULL) {
        head = newMember;
        printf("\n Welcome to our mailing list, %s!\n\n", name);
    } else {
        Member *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newMember;
        printf("\n Thank you for joining our mailing list, %s!\n\n", name);
    }
}

void removeMember(char email[]) {
    Member *temp = head;
    Member *previous = NULL;
    while (temp != NULL) {
        if (strcmp(temp->email, email) == 0) {
            if (previous == NULL) {
                head = temp->next;
            } else {
                previous->next = temp->next;
            }
            printf("\n %s has been removed from our mailing list.\n\n", temp->name);
            free(temp);
            return;
        }
        previous = temp;
        temp = temp->next;
    }
    printf("\n Sorry, we couldn't find %s in our mailing list.\n\n", email);
}

void printList() {
    printf("\n ------- Mailing list -------\n\n");
    if (head == NULL) {
        printf(" No members in the list!\n\n");
    } else {
        Member *current = head;
        while (current != NULL) {
            printf(" Name: %s\n Email: %s\n\n", current->name, current->email);
            current = current->next;
        }
    }
}

void sendMessage(char subject[], char message[]) {
    printf("\n\n ------- Sending message -------\n\n");
    if (head == NULL) {
        printf(" No members in the list to send message to!\n\n");
    } else {
        Member *current = head;
        while (current != NULL) {
            printf(" To: %s (%s)\n Subject: %s\n Message: %s\n\n", current->name, current->email, subject, message);
            current = current->next;
        }
    }
}

int main() {
    printf("\n\n Welcome to the Surrealist Mailing List Manager! \n\n");

    /*
    Code to generate random members and add to the list
    */
    char names[][50] = {"Theodore", "Ava", "Penelope", "Graham", "Lila", "Ryder", "Mabel", "Kieran", "Sloane", "August", "Violet", "Oscar", "Matilda", "Hugo", "Ada", "Jasper", "Francesca", "Finn", "Cora", "Julian", "Alice", "Leo", "Eloise", "Maximilian", "Iris"};
    char domains[][10] = {"gmail", "hotmail", "yahoo", "outlook"};
    char extensions[][4] = {"com", "edu", "org"};

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        char name[50];
        strcpy(name, names[rand() % 25]);
        char email[50];
        strcpy(email, name);
        strcat(email, "@");
        strcat(email, domains[rand() % 4]);
        strcat(email, ".");
        strcat(email, extensions[rand() % 3]);
        addMember(name, email);
    }

    /*
    Code to interact with the user
    */
    while (1) {
        printf(" What would you like to do?\n\n");
        printf(" 1. Add a member to the list\n");
        printf(" 2. Remove a member from the list\n");
        printf(" 3. Print the list of members\n");
        printf(" 4. Send a message to all members\n");
        printf(" 5. Exit program\n\n");
        printf(" Enter your choice (1-5): ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("\n Enter the name of the member: ");
                char name[50];
                scanf("%s", name);
                printf(" Enter the email of the member: ");
                char email[50];
                scanf("%s", email);
                addMember(name, email);
                break;
            }

            case 2: {
                printf("\n Enter the email of the member to be removed: ");
                char email[50];
                scanf("%s", email);
                removeMember(email);
                break;
            }

            case 3: {
                printList();
                break;
            }

            case 4: {
                printf("\n Enter subject of the message: ");
                char subject[50];
                scanf("%s", subject);
                printf(" Enter message to be sent: ");
                char message[100];
                scanf("%s", message);
                sendMessage(subject, message);
                break;
            }

            case 5: {
                printf("\n Thank you for using the Surrealist Mailing List Manager. \n\n");
                exit(0);
            }

            default: {
                printf("\n Invalid choice, please try again. \n\n");
                break;
            }
        }
    }
    return 0;
}