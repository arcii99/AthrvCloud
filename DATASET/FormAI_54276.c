//FormAI DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 50
#define MAX_EMAIL_SIZE 100
#define MAX_MEMBERS 1000

struct Member {
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
};

int main() {
    struct Member members[MAX_MEMBERS];
    int num_members = 0;

    char input[MAX_NAME_SIZE + MAX_EMAIL_SIZE + 3];
    char* name;
    char* email;

    while (1) {
        printf("Enter name and email (or 'quit' to exit): ");
        fgets(input, MAX_NAME_SIZE + MAX_EMAIL_SIZE + 3, stdin);

        if (strncmp(input, "quit", 4) == 0) {
            break;
        }

        name = strtok(input, " ");
        if (name == NULL) {
            printf("Invalid input\n");
            continue;
        }

        email = strtok(NULL, "\n");
        if (email == NULL) {
            printf("Invalid input\n");
            continue;
        }

        if (strlen(name) >= MAX_NAME_SIZE || strlen(email) >= MAX_EMAIL_SIZE) {
            printf("Input too long\n");
            continue;
        }

        strcpy(members[num_members].name, name);
        strcpy(members[num_members].email, email);
        num_members++;

        if (num_members == MAX_MEMBERS) {
            printf("Maximum number of members reached\n");
            break;
        }
    }

    printf("\n%d members added:\n", num_members);
    for (int i = 0; i < num_members; i++) {
        printf("%d. %s (%s)\n", i+1, members[i].name, members[i].email);
    }

    return 0;
}