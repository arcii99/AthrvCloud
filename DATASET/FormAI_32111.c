//FormAI DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to check if the user is an admin
int isAdmin(char *username){
    if(strcmp(username, "root") == 0){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to grant superuser privileges
void grantSuperuserPrivileges(){
    // Code to grant superuser privileges goes here
}

int main(){
    char username[50];
    printf("Please enter your username: ");
    scanf("%s", username);

    // Check if the user is an admin
    if(isAdmin(username)){
        printf("Welcome, %s! You are an admin.\n", username);
        grantSuperuserPrivileges();
    }
    else{
        printf("Sorry, %s, you do not have admin privileges.\n", username);
    }

    return 0;
}