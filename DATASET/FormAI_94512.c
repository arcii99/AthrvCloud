//FormAI DATASET v1.0 Category: Mailing list manager ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_LENGTH 100

// Function for adding email to the mailing list
int addEmail(char email[MAX_LENGTH], char mailingList[MAX_EMAILS][MAX_LENGTH], int count) {
    // Check if email already exists in the list
    for (int i = 0; i < count; i++) {
        if (strcmp(email, mailingList[i]) == 0) {
            printf("Email already exists in mailing list!\n");
            return count;
        }
    }
    // Add email to the list
    strcpy(mailingList[count], email);
    printf("Email added to mailing list!\n");
    return ++count;
}

// Function for removing email from the mailing list
int removeEmail(char email[MAX_LENGTH], char mailingList[MAX_EMAILS][MAX_LENGTH], int count) {
    int index = -1;
    // Find index of email in the list
    for (int i = 0; i < count; i++) {
        if (strcmp(email, mailingList[i]) == 0) {
            index = i;
            break;
        }
    }
    // Shift all elements after the removed email one index to the left
    if (index != -1) {
        for (int i = index; i < count - 1; i++) {
            strcpy(mailingList[i], mailingList[i + 1]);
        }
        // Clear last element
        strcpy(mailingList[count - 1], "");
        printf("Email removed from mailing list!\n");
        return --count;
    } else {
        printf("Email not found in mailing list!\n");
        return count;
    }
}

// Function for printing all emails in the mailing list
void printMailingList(char mailingList[MAX_EMAILS][MAX_LENGTH], int count) {
    printf("Mailing list:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", mailingList[i]);
    }
}

int main() {
    char mailingList[MAX_EMAILS][MAX_LENGTH] = {""};
    int count = 0;

    // Menu for managing the mailing list
    printf("Welcome to the mailing list manager!\n");
    while (1) {
        printf("1. Add email\n2. Remove email\n3. Print mailing list\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                char addEmailString[MAX_LENGTH];
                scanf("%s", addEmailString);
                count = addEmail(addEmailString, mailingList, count);
                break;
            case 2:
                printf("Enter email to remove: ");
                char removeEmailString[MAX_LENGTH];
                scanf("%s", removeEmailString);
                count = removeEmail(removeEmailString, mailingList, count);
                break;
            case 3:
                printMailingList(mailingList, count);
                break;
            case 4:
                printf("Exiting mailing list manager...\n");
                return 0;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}