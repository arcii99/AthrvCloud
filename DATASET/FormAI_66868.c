//FormAI DATASET v1.0 Category: Mailing list manager ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMAILS 1000 // maximum number of emails that can be stored

struct email {
    char name[50];
    char email_addr[50];
};

struct email_list {
    int count; // number of emails currently in the list
    struct email emails[MAX_EMAILS]; // array of emails
};

void add_email(struct email_list *list, char *name, char *email_addr) {
    if (list->count == MAX_EMAILS) { // check if list is already full
        printf("Email list is full. Cannot add new email.\n");
        return;
    }
    // allocate memory for new email
    struct email new_email = { .name = "", .email_addr = "" };
    strcpy(new_email.name, name);
    strcpy(new_email.email_addr, email_addr);
    // add new email to end of list
    list->emails[list->count] = new_email;
    list->count++;
    printf("Email added successfully.\n");
}

void delete_email(struct email_list *list, int index) {
    if (index < 0 || index >= list->count) { // check if index is out of bounds
        printf("Invalid index. No email deleted.\n");
        return;
    }
    // move all subsequent emails back by one index to fill gap left by deleted email
    for (int i = index; i < list->count-1; i++) {
        list->emails[i] = list->emails[i+1];
    }
    list->count--;
    printf("Email deleted successfully.\n");
}

void print_email_list(struct email_list *list) {
    printf("Email List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s: %s\n", i+1, list->emails[i].name, list->emails[i].email_addr);
    }
}

void save_email_list(struct email_list *list, char *filename) {
    FILE *fp = fopen(filename, "w"); // open file for writing
    if (fp == NULL) {
        printf("Error opening file %s. Email list not saved.\n", filename);
        return;
    }
    // write email list to file
    for (int i = 0; i < list->count; i++) {
        fprintf(fp, "%s,%s\n", list->emails[i].name, list->emails[i].email_addr);
    }
    fclose(fp); // close file
    printf("Email list saved successfully to %s.\n", filename);
}

void load_email_list(struct email_list *list, char *filename) {
    FILE *fp = fopen(filename, "r"); // open file for reading
    if (fp == NULL) {
        printf("Error opening file %s. Email list not loaded.\n", filename);
        return;
    }
    // read email list from file
    char line[100];
    while (fgets(line, 100, fp) != NULL) {
        char *name = strtok(line, ",");
        char *email_addr = strtok(NULL, ",");
        add_email(list, name, email_addr);
    }
    fclose(fp); // close file
    printf("Email list loaded successfully from %s.\n", filename);
}

int main() {
    struct email_list list = { .count = 0 };
    int choice, index;
    char name[50], email_addr[50], filename[50];

    while (1) {
        // display menu of options
        printf("1. Add Email\n");
        printf("2. Delete Email\n");
        printf("3. Print Email List\n");
        printf("4. Save Email List\n");
        printf("5. Load Email List\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email address: ");
                scanf("%s", email_addr);
                add_email(&list, name, email_addr);
                break;
            case 2:
                printf("Enter index of email to delete: ");
                scanf("%d", &index);
                delete_email(&list, index-1);
                break;
            case 3:
                print_email_list(&list);
                break;
            case 4:
                printf("Enter filename to save email list to: ");
                scanf("%s", filename);
                save_email_list(&list, filename);
                break;
            case 5:
                printf("Enter filename to load email list from: ");
                scanf("%s", filename);
                load_email_list(&list, filename);
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}