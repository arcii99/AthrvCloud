//FormAI DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 20

struct Password_Manager {
    char passwords[MAX_PASSWORDS][PASSWORD_LENGTH];
    int num_of_passwords;
};

void add_password(struct Password_Manager* pm, const char* password) {
    if (pm->num_of_passwords < MAX_PASSWORDS) {
        strcpy(pm->passwords[pm->num_of_passwords], password);
        pm->num_of_passwords++;
        printf("Password added successfully.\n");
    } else {
        printf("Maximum number of passwords reached.\n");
    }
}

void view_all_passwords(struct Password_Manager* pm) {
    if (pm->num_of_passwords == 0) {
        printf("No passwords found.\n");
    } else {
        printf("All passwords:\n");
        for (int i = 0; i < pm->num_of_passwords; i++) {
            printf("%s\n", pm->passwords[i]);
        }
    }
}

int main() {
    struct Password_Manager pm;
    pm.num_of_passwords = 0;

    add_password(&pm, "password123");
    add_password(&pm, "qwertyuiop");
    view_all_passwords(&pm);

    return 0;
}