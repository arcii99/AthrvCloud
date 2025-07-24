//FormAI DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <string.h>

struct Contact {
    char name[20];
    char mobile[15];
    char email[30];
};

int main() {
    struct Contact contacts[100];
    int count = 0;

    printf("\nWelcome to your cheerful Phone Book! Let's add some contacts!\n");

    while (1) {
        printf("\nEnter name (quit to exit): ");
        scanf("%s", contacts[count].name);
        if (strcmp(contacts[count].name, "quit") == 0)
            break;

        printf("Enter mobile: ");
        scanf("%s", contacts[count].mobile);

        printf("Enter email: ");
        scanf("%s", contacts[count].email);

        printf("\nContact added successfully!\n");
        count++;
    }

    printf("\nYour Phone Book contains the following contacts:\n");

    for (int i = 0; i < count; i++) {
        printf("Contact %d\nName: %s\nMobile: %s\nEmail: %s\n\n", i+1, contacts[i].name, contacts[i].mobile, contacts[i].email);
    }

    printf("Thank you for using your cheerful Phone Book!");
    return 0;
}