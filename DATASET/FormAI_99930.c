//FormAI DATASET v1.0 Category: System administration ; Style: inquisitive
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the System Administration Example!\n");
    printf("This program will help you perform a basic system administration task of creating a new user account.\n");
    char username[20];
    char password[20];
    printf("Please enter the username you want to create: ");
    scanf("%s",username);
    printf("Please enter the password for the user: ");
    scanf("%s",password);
    printf("Creating user '%s' with password '%s'...\n",username,password);
    char command[50];
    snprintf(command,sizeof(command),"sudo useradd -m %s",username);
    system(command);
    snprintf(command,sizeof(command),"sudo passwd %s %s",username,password);
    system(command);
    printf("User account creation successful!\n");
    return 0;
}