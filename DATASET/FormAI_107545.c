//FormAI DATASET v1.0 Category: Mailing list manager ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000 // Maximum number of emails that can be stored
#define MAX_NAME 50 // Maximum length of a name
#define MAX_EMAIL 80 // Maximum length of an email address

// Struct to hold a single email address
typedef struct {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
} Email;

// Struct to hold multiple email addresses
typedef struct {
    Email emails[MAX_EMAILS]; // Array of emails
    int count; // Number of emails currently stored
} EmailList;

// Function prototypes
void addEmail(EmailList *list);
void removeEmail(EmailList *list);
void printEmails(EmailList *list);
void saveToFile(EmailList *list, char *filename);
void loadFromFile(EmailList *list, char *filename);

int main() {
    EmailList list = {0}; // Initialize the list with count = 0
    int choice;
    char filename[100];

    printf("Welcome to the Email List Manager!\n\n");

    while (1) {
        // Display menu and get user choice
        printf("1. Add email\n");
        printf("2. Remove email\n");
        printf("3. Print emails\n");
        printf("4. Save to file\n");
        printf("5. Load from file\n");
        printf("6. Quit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        printf("\n");

        // Perform action based on user choice
        switch (choice) {
            case 1:
                addEmail(&list);
                break;
            case 2:
                removeEmail(&list);
                break;
            case 3:
                printEmails(&list);
                break;
            case 4:
                printf("Enter filename to save to: ");
                scanf("%s", filename);
                saveToFile(&list, filename);
                break;
            case 5:
                printf("Enter filename to load from: ");
                scanf("%s", filename);
                loadFromFile(&list, filename);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }

        printf("\n");
    }

    return 0;
}

void addEmail(EmailList *list) {
    // Ensure list is not full
    if (list->count >= MAX_EMAILS) {
        printf("Error: list is full!\n");
        return;
    }

    // Get input from user
    printf("Enter name: ");
    scanf("%s", list->emails[list->count].name);
    printf("Enter email address: ");
    scanf("%s", list->emails[list->count].email);

    // Increment count
    list->count++;

    printf("Email added successfully!\n");
}

void removeEmail(EmailList *list) {
    // Ensure list is not empty
    if (list->count <= 0) {
        printf("Error: list is empty!\n");
        return;
    }

    // Get input from user
    char name[MAX_NAME];
    printf("Enter name to remove email: ");
    scanf("%s", name);

    // Search for email with given name and shift all elements after it back by one
    int i;
    for (i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i].name, name) == 0) {
            // Found matching email, shift all elements after it back by one
            int j;
            for (j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j].name, list->emails[j + 1].name);
                strcpy(list->emails[j].email, list->emails[j + 1].email);
            }

            // Decrement count
            list->count--;

            printf("Email removed successfully!\n");
            return;
        }
    }

    // Email with given name was not found
    printf("Error: email with name '%s' not found!\n", name);
}

void printEmails(EmailList *list) {
    // Ensure list is not empty
    if (list->count <= 0) {
        printf("Error: list is empty!\n");
        return;
    }

    // Loop through all emails and print them
    int i;
    for (i = 0; i < list->count; i++) {
        printf("%s: %s\n", list->emails[i].name, list->emails[i].email);
    }
}

void saveToFile(EmailList *list, char *filename) {
    // Ensure list is not empty
    if (list->count <= 0) {
        printf("Error: list is empty!\n");
        return;
    }

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: could not open file '%s' for writing!\n", filename);
        return;
    }

    // Loop through all emails and write them to file
    int i;
    for (i = 0; i < list->count; i++) {
        fprintf(fp, "%s,%s\n", list->emails[i].name, list->emails[i].email);
    }

    fclose(fp);

    printf("Email list saved to file '%s' successfully!\n", filename);
}

void loadFromFile(EmailList *list, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: could not open file '%s' for reading!\n", filename);
        return;
    }

    // Clear current email list
    list->count = 0;

    // Read emails from file and store in list
    char line[MAX_NAME + MAX_EMAIL + 1];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *name = strtok(line, ",");
        char *email = strtok(NULL, ",\n");

        // Ensure name and email are valid
        if (!name || !email) {
            printf("Error: invalid line in file '%s'!\n", filename);
            fclose(fp);
            return;
        }

        // Remove any trailing newline characters from email
        int len = strlen(email);
        if (len > 0 && email[len - 1] == '\n') {
            email[len - 1] = '\0';
        }

        // Add email to list
        strcpy(list->emails[list->count].name, name);
        strcpy(list->emails[list->count].email, email);
        list->count++;
    }

    fclose(fp);

    printf("Email list loaded from file '%s' successfully!\n", filename);
}