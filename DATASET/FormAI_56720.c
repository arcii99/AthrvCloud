//FormAI DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int choice;

    while(1) {
        printf("\nWelcome to the System Administration Program:\n");
        printf("1. Check system information\n");
        printf("2. Manage users and groups\n");
        printf("3. Configure network settings\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                system("uname -a"); // Prints system information using uname command
                break;

            case 2:
                manage_users_groups();
                break;

            case 3:
                configure_network_settings(); 
                break;

            case 4:
                printf("\nThank you for using the System Administration Program.\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}

void manage_users_groups() 
{
    int choice2;

    while(1) {
        printf("\nManage users and groups:\n");
        printf("1. Create a user\n");
        printf("2. Delete a user\n");
        printf("3. Add a user to group\n");
        printf("4. Remove a user from group\n");
        printf("5. Return to the previous menu\n");

        printf("Enter your choice: ");
        scanf("%d", &choice2);

        switch(choice2) {
            case 1:
                create_user();
                break;

            case 2:
                delete_user();
                break;

            case 3:
                add_user_to_group();
                break;

            case 4:
                remove_user_from_group();
                break;

            case 5:
                return;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}

void create_user()
{
    char username[20];

    printf("\nEnter the username: ");
    scanf("%s", username);

    // Add user to system using useradd command
    char command[50];
    sprintf(command, "sudo useradd %s", username);

    // Check if user was added successfully
    if(system(command) == -1) {
        printf("Error: Unable to add user.\n");
    } else {
        printf("User %s has been successfully added to the system.\n", username);
    }
}

void delete_user()
{
    char username[20];

    printf("\nEnter the username: ");
    scanf("%s", username);

    // Delete user from system using userdel command
    char command[50];
    sprintf(command, "sudo userdel %s", username);

    // Check if user was deleted successfully
    if(system(command) == -1) {
        printf("Error: Unable to delete user.\n");
    } else {
        printf("User %s has been successfully deleted from the system.\n", username);
    }
}

void add_user_to_group()
{
    char username[20], groupname[20];

    printf("Enter the username: ");
    scanf("%s", username);

    printf("Enter the groupname: ");
    scanf("%s", groupname);

    // Add user to group using usermod command
    char command[50];
    sprintf(command, "sudo usermod -a -G %s %s", groupname, username);

    // Check if user was added to the group successfully
    if(system(command) == -1) {
        printf("Error: Unable to add user to group.\n");
    } else {
        printf("User %s has been successfully added to group %s.\n", username, groupname);
    }
}

void remove_user_from_group()
{
    char username[20], groupname[20];

    printf("Enter the username: ");
    scanf("%s", username);

    printf("Enter the groupname: ");
    scanf("%s", groupname);

    // Remove user from group using gpasswd command
    char command[50];
    sprintf(command, "sudo gpasswd -d %s %s", username, groupname);

    // Check if user was removed from the group successfully
    if(system(command) == -1) {
        printf("Error: Unable to remove user from group.\n");
    } else {
        printf("User %s has been successfully removed from group %s.\n", username, groupname);
    }
}

void configure_network_settings()
{
    int choice3;

    while(1) {
        printf("\nConfigure network settings:\n");
        printf("1. Display IP address\n");
        printf("2. Configure static IP address\n");
        printf("3. Configure DHCP\n");
        printf("4. Return to the previous menu\n");

        printf("Enter your choice: ");
        scanf("%d", &choice3);

        switch(choice3) {
            case 1:
                system("ifconfig"); // Prints IP address using ifconfig command
                break;

            case 2:
                configure_static_ip();
                break;

            case 3:
                configure_dhcp();
                break;

            case 4:
                return;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}

void configure_static_ip()
{
    char address[20], netmask[20], gateway[20];

    printf("Enter the IP address: ");
    scanf("%s", address);

    printf("Enter the network mask: ");
    scanf("%s", netmask);

    printf("Enter the gateway address: ");
    scanf("%s", gateway);

    // Configure static IP using ifconfig command
    char command[100];
    sprintf(command, "sudo ifconfig eth0 %s netmask %s && sudo route add default gw %s", address, netmask, gateway);

    // Check if static IP was configured successfully
    if(system(command) == -1) {
        printf("Error: Unable to configure static IP.\n");
    } else {
        printf("Static IP address has been successfully configured.\n");
    }
}

void configure_dhcp()
{
    // Configure DHCP using dhclient command
    char command[50];
    sprintf(command, "sudo dhclient eth0");

    // Check if DHCP was configured successfully
    if(system(command) == -1) {
        printf("Error: Unable to configure DHCP.\n");
    } else {
        printf("DHCP has been successfully configured.\n");
    }
}