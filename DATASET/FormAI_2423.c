//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of members in mailing list
#define MAX_MEMBERS 100

// Define structure for storing member information
struct MailingListMember {
    char name[50];
    char email[50];
};

// Define function to print the menu
void printMenu() {
    printf("Mailing List Manager\n");
    printf("1. Add Member\n");
    printf("2. Remove Member\n");
    printf("3. Print Mailing List\n");
    printf("4. Save Mailing List to File\n");
    printf("5. Load Mailing List from File\n");
    printf("6. Exit\n");
}

int main() {
    // Declare variables
    struct MailingListMember mailingList[MAX_MEMBERS];
    int numMembers = 0;
    int choice;

    // Loop through menu options until user chooses to exit
    do {
        printMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Add member to mailing list
                if(numMembers >= MAX_MEMBERS) {
                    printf("Mailing List is full!\n");
                } else {
                    printf("Enter name: ");
                    scanf("%s", mailingList[numMembers].name);
                    printf("Enter email: ");
                    scanf("%s", mailingList[numMembers].email);
                    numMembers++;
                    printf("Member added to mailing list.\n");
                }
                break;
            case 2:
                // Remove member from mailing list
                if(numMembers == 0) {
                    printf("No members in mailing list!\n");
                } else {
                    char emailToRemove[50];
                    printf("Enter email of member to remove: ");
                    scanf("%s", emailToRemove);
                    int found = 0;
                    for(int i = 0; i < numMembers; i++) {
                        if(strcmp(mailingList[i].email, emailToRemove) == 0) {
                            // Remove member from mailing list
                            for(int j = i; j < numMembers - 1; j++) {
                                strcpy(mailingList[j].name, mailingList[j+1].name);
                                strcpy(mailingList[j].email, mailingList[j+1].email);
                            }
                            numMembers--;
                            found = 1;
                            printf("Member removed from mailing list.\n");
                            break;
                        }
                    }
                    if(!found) {
                        printf("Member with email %s not found in mailing list.\n", emailToRemove);
                    }
                }
                break;
            case 3:
                // Print mailing list
                if(numMembers == 0) {
                    printf("No members in mailing list!\n");
                } else {
                    printf("Mailing List\n");
                    printf("------------\n");
                    for(int i = 0; i < numMembers; i++) {
                        printf("%s, %s\n", mailingList[i].name, mailingList[i].email);
                    }
                }
                break;
            case 4:
                // Save mailing list to file
                if(numMembers == 0) {
                    printf("No members in mailing list!\n");
                } else {
                    FILE *fp;
                    fp = fopen("mailing_list.txt", "w");
                    for(int i = 0; i < numMembers; i++) {
                        fprintf(fp, "%s,%s\n", mailingList[i].name, mailingList[i].email);
                    }
                    fclose(fp);
                    printf("Mailing list saved to file.\n");
                }
                break;
            case 5:
                // Load mailing list from file
                numMembers = 0; // Clear existing mailing list
                FILE *fp;
                fp = fopen("mailing_list.txt", "r");
                if(fp == NULL) {
                    printf("File not found!\n");
                } else {
                    char line[100];
                    while(fgets(line, 100, fp) != NULL) {
                        char *name = strtok(line, ",");
                        char *email = strtok(NULL, ",");
                        strtok(email, "\n"); // Remove newline character from email
                        strcpy(mailingList[numMembers].name, name);
                        strcpy(mailingList[numMembers].email, email);
                        numMembers++;
                    }
                    fclose(fp);
                    printf("Mailing list loaded from file.\n");
                }
                break;
            case 6:
                // Exit program
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 6);

    return 0;
}