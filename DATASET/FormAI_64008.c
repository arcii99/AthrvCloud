//FormAI DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to generate a random password
void generate_password(char* password, int length){
    // initialization of characters
    char numbers[10] = "0123456789";
    char uppercase[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase[27] = "abcdefghijklmnopqrstuvwxyz";
    char symbols[11] = "!@#$%^&*()_+";

    // seed the random generator
    srand(time(NULL));

    // generate the password
    int i;
    for(i=0; i<length; i++){
        // determine which character type to use
        int type = rand() % 4;

        switch(type){
            case 0:
                password[i] = numbers[rand() % 10];
                break;
            case 1:
                password[i] = uppercase[rand() % 26];
                break;
            case 2:
                password[i] = lowercase[rand() % 26];
                break;
            case 3:
                password[i] = symbols[rand() % 10];
                break;
            default:
                break;
        }
    }
    // add null terminator
    password[length] = '\0';
}

int main(){
    char username[20];
    char password[20];
    char new_password[20];

    // get the username and password from the user
    printf("Enter your username: ");
    fgets(username, 20, stdin);
    strtok(username, "\n");
    printf("Enter your password: ");
    fgets(password, 20, stdin);
    strtok(password, "\n");

    // verify the user's password
    if(strcmp(password, "password123") == 0){
        printf("Welcome, %s!\n", username);

        // give the user the option to change their password
        printf("Would you like to change your password? (yes or no): ");
        char response[3];
        fgets(response, 3, stdin);
        strtok(response, "\n");
        if(strcmp(response, "yes") == 0){
            printf("Enter your new password: ");
            fgets(new_password, 20, stdin);
            strtok(new_password, "\n");

            // generate a random password if the user does not enter one
            if(strlen(new_password) == 0){
                generate_password(new_password, 10);
                printf("Your new password is: %s\n", new_password);
            }
            else{
                printf("Your new password is: %s\n", new_password);
            }
        }
        else{
            printf("Okay, have a nice day!\n");
        }
    }
    else{
        printf("Incorrect password. Access denied.\n");
    }

    return 0;
}