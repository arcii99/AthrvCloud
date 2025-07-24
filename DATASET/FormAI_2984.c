//FormAI DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 30
#define MAX_LIST_MEMBERS 100
#define MAX_LIST_NAME_LENGTH 100
#define MASTER_PASSWORD "mysecretpassword"

// Define the Email struct
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Email;

// Define the Mailing List struct
typedef struct {
    char listName[MAX_LIST_NAME_LENGTH];
    int numMembers;
    Email members[MAX_LIST_MEMBERS];
} MailingList;

// Define the function to check if a password is valid
int checkPassword(char* password) {
    if(strcmp(password, MASTER_PASSWORD) == 0) {
        return 1;
    }
    return 0;
}

// Define the function to add a member to a mailing list
void addMember(MailingList* list, char* name, char* email) {
    // Check if the list is full
    if(list->numMembers == MAX_LIST_MEMBERS) {
        printf("The mailing list is full. No new members can be added.\n");
        return;
    }
    // Check if the member already exists in the list
    for(int i = 0; i < list->numMembers; i++) {
        if(strcmp(list->members[i].email, email) == 0) {
            printf("This email already exists in the mailing list. No member added.\n");
            return;
        }
    }
    // Add the member to the list
    strcpy(list->members[list->numMembers].name, name);
    strcpy(list->members[list->numMembers].email, email);
    list->numMembers++;
    printf("Successfully added %s <%s> to the mailing list.\n", name, email);
}

// Define the function to remove a member from a mailing list
void removeMember(MailingList* list, char* email) {
    // Check if the member is in the list
    for(int i = 0; i < list->numMembers; i++) {
        if(strcmp(list->members[i].email, email) == 0) {
            // Shift all the members after the removed member one position to the left
            for(int j = i; j < list->numMembers - 1; j++) {
                strcpy(list->members[j].name, list->members[j+1].name);
                strcpy(list->members[j].email, list->members[j+1].email);
            }
            // Clear the last member in the list
            strcpy(list->members[list->numMembers-1].name, "");
            strcpy(list->members[list->numMembers-1].email, "");
            list->numMembers--;
            printf("Successfully removed <%s> from the mailing list.\n", email);
            return;
        }
    }
    printf("This email does not exist in the mailing list. No member removed.\n");
}

// Define the main function
int main() {
    // Define the list
    MailingList myMailingList = {"My Mailing List", 0};
    // Prompt for the password
    char password[100];
    printf("Enter the password to access the mailing list: ");
    scanf("%s", password);
    // Check the password
    if(checkPassword(password)) {
        // Print the menu
        printf("\nWelcome to the Mailing List Manager!\n");
        printf("===================================\n");
        printf("1. Add member\n");
        printf("2. Remove member\n");
        printf("3. List members\n");
        printf("4. Quit\n");
        int choice = 0;
        // Loop until the user quits
        while(choice != 4) {
            printf("\nEnter your choice (1-4): ");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    // Prompt for the member's name and email
                    char name[MAX_NAME_LENGTH];
                    char email[MAX_EMAIL_LENGTH];
                    printf("Enter the member's name: ");
                    scanf("%s", name);
                    printf("Enter the member's email: ");
                    scanf("%s", email);
                    // Add the member to the list
                    addMember(&myMailingList, name, email);
                    break;
                case 2:
                    // Prompt for the email of the member to remove
                    char removeEmail[MAX_EMAIL_LENGTH];
                    printf("Enter the email of the member to remove: ");
                    scanf("%s", removeEmail);
                    // Remove the member from the list
                    removeMember(&myMailingList, removeEmail);
                    break;
                case 3:
                    // Print the members in the list
                    printf("\n%s Members:\n", myMailingList.listName);
                    printf("=============================\n");
                    for(int i = 0; i < myMailingList.numMembers; i++) {
                        printf("%s <%s>\n", myMailingList.members[i].name, myMailingList.members[i].email);
                    }
                    break;
                case 4:
                    // Quit the program
                    printf("Goodbye!\n");
                    break;
                default:
                    // Invalid choice
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
        }
    }
    else {
        // Incorrect password
        printf("Incorrect password. Access denied.\n");
    }
    return 0;
}