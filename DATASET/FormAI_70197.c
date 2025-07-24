//FormAI DATASET v1.0 Category: Mailing list manager ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "mailing_list.txt" // File path for storing mailing list data
#define MAX_NAME_LENGTH 50 // Maximum length of recipient name
#define MAX_EMAIL_LENGTH 100 // Maximum length of recipient email
#define MAX_LIST_SIZE 1000 // Maximum number of recipients in mailing list

// Structure for a recipient in the mailing list
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Recipient;

// Function to add recipient to the mailing list
void addRecipient(Recipient *list, int *size) {
    if (*size >= MAX_LIST_SIZE) {
        printf("Maximum recipients reached!\n");
        return;
    }
    Recipient newRecipient;
    printf("Enter recipient name: ");
    fgets(newRecipient.name, MAX_NAME_LENGTH, stdin);
    printf("Enter recipient email: ");
    fgets(newRecipient.email, MAX_EMAIL_LENGTH, stdin);
    list[*size] = newRecipient;
    (*size)++;
    printf("Recipient added to mailing list!\n");
}

// Function to display all recipients in the mailing list
void displayRecipients(Recipient *list, int size) {
    if (size == 0) {
        printf("Mailing list is empty!\n");
        return;
    }
    printf("Recipients in mailing list:\n");
    for (int i = 0; i < size; i++) {
        printf("%s - %s", list[i].name, list[i].email);
    }
}

// Function to save mailing list data to a file
void saveListToFile(Recipient *list, int size) {
    FILE *file = fopen(FILE_PATH, "w");
    if (file == NULL) {
        printf("Failed to open file for writing!\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s:%s", list[i].name, list[i].email);
    }
    fclose(file);
    printf("Mailing list saved to file!\n");
}

// Function to load mailing list data from a file
void loadListFromFile(Recipient *list, int *size) {
    FILE *file = fopen(FILE_PATH, "r");
    if (file == NULL) {
        printf("No existing mailing list data!\n");
        return;
    }
    char line[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 2];
    while (fgets(line, MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 2, file)) {
        char *delimiter = strchr(line, ':'); // Find delimiter character between recipient name and email
        if (delimiter == NULL || delimiter == line) {
            continue; // Skip invalid lines with missing or empty recipient name
        }
        int nameLength = delimiter - line;
        strncpy(list[*size].name, line, nameLength);
        list[*size].name[nameLength] = '\0'; // Add null terminator to recipient name
        strncpy(list[*size].email, delimiter+1, MAX_EMAIL_LENGTH);
        // Remove newline character at the end of email string if present
        size_t length = strlen(list[*size].email);
        if (list[*size].email[length - 1] == '\n') {
            list[*size].email[length - 1] = '\0';
        }
        (*size)++;
        if (*size >= MAX_LIST_SIZE) {
            printf("Maximum recipients reached!\n");
            break;
        }
    }
    fclose(file);
    printf("Mailing list loaded from file!\n");
}

int main() {
    Recipient mailingList[MAX_LIST_SIZE];
    int listSize = 0;
    loadListFromFile(mailingList, &listSize);
    char input[10];
    while (1) {
        printf("\nEnter command (add, display, save, exit): ");
        fgets(input, 10, stdin);
        if (strcmp(input, "add\n") == 0) {
            addRecipient(mailingList, &listSize);
        } else if (strcmp(input, "display\n") == 0) {
            displayRecipients(mailingList, listSize);
        } else if (strcmp(input, "save\n") == 0) {
            saveListToFile(mailingList, listSize);
        } else if (strcmp(input, "exit\n") == 0) {
            break;
        } else {
            printf("Invalid command!\n");
        }
    }
    return 0;
}