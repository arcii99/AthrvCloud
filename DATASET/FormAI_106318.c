//FormAI DATASET v1.0 Category: Mailing list manager ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_LEN 100

struct email {
    char name[MAX_LEN];
    char address[MAX_LEN];
    char subject[MAX_LEN];
    char message[MAX_LEN];
};

struct maillist {
    int num_emails;
    struct email emails[MAX_EMAILS];
};

int menu();
void add_email(struct maillist *list);
void print_list(struct maillist list);
void save_list(struct maillist list);

int main() {
    struct maillist list = {0};

    int choice = menu();
    while (choice != 4) {
        switch (choice) {
            case 1:
                add_email(&list);
                break;
            case 2:
                print_list(list);
                break;
            case 3:
                save_list(list);
                break;
            default:
                printf("Invalid choice\n");
        }

        choice = menu();
    }

    return 0;
}

int menu() {
    printf("1. Add an email\n");
    printf("2. Print the mail list\n");
    printf("3. Save the mail list to a file\n");
    printf("4. Quit\n");

    int choice;
    printf("Enter a choice: ");
    scanf("%d", &choice);
    // consume remaining input
    while(getchar() != '\n');

    return choice;
}

void add_email(struct maillist *list) {
    if (list->num_emails < MAX_EMAILS) {
        printf("Enter the name: ");
        fgets(list->emails[list->num_emails].name, MAX_LEN, stdin);
        printf("Enter the email address: ");
        fgets(list->emails[list->num_emails].address, MAX_LEN, stdin);
        printf("Enter the subject: ");
        fgets(list->emails[list->num_emails].subject, MAX_LEN, stdin);
        printf("Enter the message: ");
        fgets(list->emails[list->num_emails].message, MAX_LEN, stdin);

        list->num_emails++;
    } else {
        printf("Mail list is full\n");
    }
}

void print_list(struct maillist list) {
    for (int i = 0; i < list.num_emails; i++) {
        printf("%s <%s>\nSubject: %s\nMessage: %s\n\n",
               list.emails[i].name, list.emails[i].address,
               list.emails[i].subject, list.emails[i].message);
    }
}

void save_list(struct maillist list) {
    FILE *outfile = fopen("maillist.txt", "w");
    if (outfile == NULL) {
        printf("Error opening file for writing\n");
        return;
    }

    for (int i = 0; i < list.num_emails; i++) {
        fprintf(outfile, "%s <%s>\nSubject: %s\nMessage: %s\n\n",
                list.emails[i].name, list.emails[i].address,
                list.emails[i].subject, list.emails[i].message);
    }

    fclose(outfile);
}