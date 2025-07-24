//FormAI DATASET v1.0 Category: Password management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 50 //Maximum length for password

//Structure to hold password information
struct Password {
    char site[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

//Function to create a new password entry
struct Password* create_password() {
    struct Password *new_pw = malloc(sizeof(struct Password)); //Allocate memory for new password structure
    printf("Enter site for password: ");
    fgets(new_pw->site, MAX_LENGTH, stdin); //Get site name
    printf("Enter username for site '%s': ", new_pw->site);
    fgets(new_pw->username, MAX_LENGTH, stdin); //Get username
    printf("Enter password for site '%s' and username '%s': ", new_pw->site, new_pw->username);
    fgets(new_pw->password, MAX_LENGTH, stdin); //Get password
    return new_pw;
}

//Function to edit an existing password entry
void edit_password(struct Password *pw) {
    printf("Editing password for site '%s' and username '%s'\n", pw->site, pw->username);
    printf("Enter new site name (leave blank to keep '%s'): ", pw->site);
    fgets(pw->site, MAX_LENGTH, stdin); //Get new site name
    printf("Enter new username (leave blank to keep '%s'): ", pw->username);
    fgets(pw->username, MAX_LENGTH, stdin); //Get new username
    printf("Enter new password (leave blank to keep '%s'): ", pw->password);
    fgets(pw->password, MAX_LENGTH, stdin); //Get new password
}

//Function to delete an existing password entry
void delete_password(struct Password *pw) {
    printf("Deleting password for site '%s' and username '%s'\n", pw->site, pw->username);
    free(pw); //Free memory allocated for password structure
}

int main() {
    struct Password **pw_list = malloc(sizeof(struct Password*) * 10); //Allocate memory for password list
    int pw_count = 0; //Track number of passwords in list
    char input[MAX_LENGTH]; //User input buffer
    printf("Welcome to Password Manager!\n");
    while(1) {
        printf("Enter a command (add, edit, delete, list): ");
        fgets(input, MAX_LENGTH, stdin); //Get user command
        if(strcmp(input, "add\n") == 0) { //Add new password
            struct Password *new_pw = create_password();
            pw_list[pw_count++] = new_pw;
            printf("Added password for site '%s' and username '%s'\n", new_pw->site, new_pw->username);
        }
        else if(strcmp(input, "edit\n") == 0) { //Edit existing password
            printf("Enter site for password to edit: ");
            fgets(input, MAX_LENGTH, stdin); //Get site name
            for(int i=0; i<pw_count; i++) {
                if(strcmp(pw_list[i]->site, input) == 0) {
                    edit_password(pw_list[i]);
                    printf("Edited password for site '%s' and username '%s'\n", pw_list[i]->site, pw_list[i]->username);
                    break;
                }
            }
        }
        else if(strcmp(input, "delete\n") == 0) { //Delete existing password
            printf("Enter site for password to delete: ");
            fgets(input, MAX_LENGTH, stdin); //Get site name
            for(int i=0; i<pw_count; i++) {
                if(strcmp(pw_list[i]->site, input) == 0) {
                    delete_password(pw_list[i]);
                    for(int j=i; j<pw_count-1; j++) { //Shift all passwords after deleted one back one index in list
                        pw_list[j] = pw_list[j+1];
                    }
                    pw_count--;
                    printf("Deleted password for site '%s' and username '%s'\n", pw_list[i]->site, pw_list[i]->username);
                    break;
                }
            }
        }
        else if(strcmp(input, "list\n") == 0) { //List all passwords
            printf("Password list:\n");
            for(int i=0; i<pw_count; i++) {
                printf("%d. Site: %s Username: %s Password: %s", i+1, pw_list[i]->site, pw_list[i]->username, pw_list[i]->password);
            }
        }
        else {
            printf("Invalid command\n");
        }
    }
    return 0;
}