//FormAI DATASET v1.0 Category: Mailing list manager ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000

struct EmailList {
    char name[50];
    char email[50];
};

struct MailingList {
    struct EmailList emails[MAX_EMAILS];
    int count;
};

int addEmail(struct MailingList *list, char *name, char *email) {
    if (list->count >= MAX_EMAILS) {
        return 0; // Mailing list is full
    }

    strcpy(list->emails[list->count].name, name);
    strcpy(list->emails[list->count].email, email);
    list->count++;

    return 1; // Email added successfully
}

int removeEmail(struct MailingList *list, char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i].email, email) == 0) {
            for (int j = i + 1; j < list->count; j++) {
                strcpy(list->emails[j - 1].name, list->emails[j].name);
                strcpy(list->emails[j - 1].email, list->emails[j].email);
            }
            list->count--;
            return 1; // Email removed successfully
        }
    }

    return 0; // Email not found
}

void printList(struct MailingList *list) {
    printf("Mailing List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("Name: %s\n", list->emails[i].name);
        printf("Email: %s\n", list->emails[i].email);
        printf("\n");
    }
}

void saveList(struct MailingList *list, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp != NULL) {
        fprintf(fp, "Name,Email\n");
        for (int i = 0; i < list->count; i++) {
            fprintf(fp, "%s,%s\n", list->emails[i].name, list->emails[i].email);
        }
        fclose(fp);
    }
}

int main() {
    struct MailingList list;
    list.count = 0;

    int choice;
    char name[50], email[50], filename[100];

    do {
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Print List\n");
        printf("4. Save List to File\n");
        printf("5. Quit\n");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                if (addEmail(&list, name, email)) {
                    printf("Email added successfully.\n");
                } else {
                    printf("Mailing list is full.\n");
                }
                break;
            case 2:
                printf("Enter email: ");
                scanf("%s", email);
                if (removeEmail(&list, email)) {
                    printf("Email removed successfully.\n");
                } else {
                    printf("Email not found.\n");
                }
                break;
            case 3:
                printList(&list);
                break;
            case 4:
                printf("Enter filename: ");
                scanf("%s", filename);
                saveList(&list, filename);
                printf("List saved to file.\n");
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;      
        }
    } while(choice != 5);

    return 0;
}