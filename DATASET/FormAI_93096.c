//FormAI DATASET v1.0 Category: Password management ; Style: happy
// Welcome to the Happy Password Management System!
// Here, we take all your passwords and make sure they are secure and easy to manage.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *password;
} Credential;

int main() {
    Credential *credentials = malloc(sizeof(Credential) * 10); // We can store up to 10 credentials
    int num_credentials = 0;
    char input[50];
    int i;

    printf("Welcome to the Happy Password Management System! \n");
    printf("What operation would you like to perform? (add/delete/list): ");

    while (fgets(input, 50, stdin)) {
        if (strcmp(input, "add\n") == 0) {
            if (num_credentials == 10) {
                printf("Sorry, you have reached the maximum number of credentials.\n");
                printf("What operation would you like to perform? (add/delete/list): ");
                continue;
            }
            char *name = malloc(50);
            char *password = malloc(50);
            printf("What is the name of the credential? ");
            fgets(name, 50, stdin);
            printf("What is the password? ");
            fgets(password, 50, stdin);
            Credential new_credential = {name, password};
            credentials[num_credentials] = new_credential;
            num_credentials++;
            printf("Successfully added new credential!\n");
            printf("What operation would you like to perform? (add/delete/list): ");
        }
        else if (strcmp(input, "delete\n") == 0) {
            if (num_credentials == 0) {
                printf("Sorry, you have no credentials to delete.\n");
                printf("What operation would you like to perform? (add/delete/list): ");
                continue;
            }
            printf("What is the name of the credential to delete? ");
            char *delete_name = malloc(50);
            fgets(delete_name, 50, stdin);
            for (i = 0; i < num_credentials; i++) {
                if (strcmp(credentials[i].name, delete_name) == 0) {
                    free(credentials[i].name); // Free memory for the name and password
                    free(credentials[i].password);
                    if (i == num_credentials - 1) { // If it's the last credential, simply decrement the count
                        num_credentials--;
                    }
                    else { // Shift all the credentials after the deleted one
                        for (; i < num_credentials - 1; i++) {
                            credentials[i] = credentials[i+1];
                        }
                        credentials[i] = (Credential) {"", ""}; // Set the last credential to empty values
                        num_credentials--;
                    }
                    printf("Successfully deleted the credential.\n");
                    printf("What operation would you like to perform? (add/delete/list): ");
                    break;
                }
            }
            if (i == num_credentials) { // If we went through the loop and didn't break, then the credential wasn't found
                printf("Sorry, that credential was not found.\n");
                printf("What operation would you like to perform? (add/delete/list): ");
            }
            free(delete_name);
        }
        else if (strcmp(input, "list\n") == 0) {
            if (num_credentials == 0) {
                printf("You have no credentials stored.\n");
                printf("What operation would you like to perform? (add/delete/list): ");
                continue;
            }
            printf("Here are your stored credentials:\n");
            for (i = 0; i < num_credentials; i++) {
                printf("%s: %s\n", credentials[i].name, credentials[i].password);
            }
            printf("What operation would you like to perform? (add/delete/list): ");
        }
        else {
            printf("Sorry, I didn't quite catch that. What operation would you like to perform? (add/delete/list): ");
        }
    }

    // Free memory for the credentials
    for (i = 0; i < num_credentials; i++) {
        free(credentials[i].name);
        free(credentials[i].password);
    }
    free(credentials);

    return 0;
}