//FormAI DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define EMAIL_LIST_SIZE 10

char valid_email_domains[][10] = {"gmail.com", "yahoo.com", "hotmail.com"};

int is_valid_email(char* email){
    char* domain = strrchr(email, '@');
    if (domain == NULL){
        return 0;
    }
    domain++; // exclude the '@' symbol
    for(int i=0; i<3; i++){
        if(strcmp(domain, valid_email_domains[i]) == 0){
            return 1;
        }
    }
    return 0;
}

void free_email_list(char** email_list, int num_of_emails){
    for(int i=0; i<num_of_emails; i++){
        free(email_list[i]);
    }
    free(email_list);
}

int main(){
    printf("Welcome to the Paranoid Email List Manager\n");
    printf("-------------------------------------------\n");

    // initialize email list
    char** email_list = (char**) malloc(sizeof(char*) * EMAIL_LIST_SIZE);
    int num_of_emails = 0;

    while(1){
        printf("\nAvailable commands: \n");
        printf("add <email> - Add email address to the list\n");
        printf("list - Print the list of email addresses\n");
        printf("remove <email> - Remove email address from the list\n");
        printf("exit - Quit the program\n");

        // get user input
        char buffer[BUFFER_SIZE];
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // remove trailing newline character

        // parse input
        char* command = strtok(buffer, " ");
        if(command == NULL){
            printf("\nInvalid command. Please try again.\n");
            continue;
        }
        
        if(strcmp(command, "add") == 0){
            char* email = strtok(NULL, " ");
            if(email == NULL){
                printf("\nInvalid email address. Please try again.\n");
                continue;
            }
            if(!is_valid_email(email)){
                printf("\nInvalid domain. Only gmail.com, yahoo.com, and hotmail.com are supported.\n");
                continue;
            }
            if(num_of_emails == EMAIL_LIST_SIZE){
                printf("\nEmail list is full.\n");
                continue;
            }
            // add email to list
            email_list[num_of_emails] = (char*) malloc(sizeof(char) * strlen(email));
            strcpy(email_list[num_of_emails], email);
            num_of_emails++;
            printf("\nEmail address has been added to the list.\n");
            
        } else if(strcmp(command, "list") == 0){
            printf("\nList of email addresses: \n");
            for(int i=0; i<num_of_emails; i++){
                printf("%s\n", email_list[i]);
            }

        } else if(strcmp(command, "remove") == 0){
            char* email = strtok(NULL, " ");
            if(email == NULL){
                printf("\nInvalid email address. Please try again.\n");
                continue;
            }
            int found = 0;
            for(int i=0; i<num_of_emails; i++){
                if(strcmp(email_list[i], email) == 0){
                    found = 1;
                    free(email_list[i]);
                    // shift emails to maintain contiguous memory
                    for(int j=i+1; j<num_of_emails; j++){
                        email_list[j-1] = email_list[j];
                    }
                    num_of_emails--;
                    printf("\nEmail address has been removed from the list.\n");
                    break;
                }
            }
            if(!found){
                printf("\nEmail address not found in list.\n");
            }

        } else if(strcmp(command, "exit") == 0){
            break;

        } else {
            printf("\nInvalid command. Please try again.\n");
        }
    }

    // free memory before exit
    free_email_list(email_list, num_of_emails);

    return 0;
}