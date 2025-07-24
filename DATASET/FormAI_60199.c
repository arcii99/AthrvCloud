//FormAI DATASET v1.0 Category: System administration ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    printf("Starting system administration tasks...\n");

    // Check if user is root
    if(getuid() != 0) {
        printf("You must be root to perform system administration tasks.\n");
        exit(1);
    }

    // Create a new user account
    printf("Creating new user account...\n");
    int status = system("useradd -m -s /bin/bash newuser");
    if(status != 0) {
        printf("Error creating new user account.\n");
        exit(1);
    }

    // Set user password
    printf("Setting new user password...\n");
    status = system("echo 'newuser:newpassword' | chpasswd");
    if(status != 0) {
        printf("Error setting user password.\n");
        exit(1);
    }

    // Add user to sudoers
    printf("Adding new user to sudoers...\n");
    status = system("echo 'newuser ALL=(ALL:ALL) ALL' >> /etc/sudoers");
    if(status != 0) {
        printf("Error adding user to sudoers.\n");
        exit(1);
    }

    // Install packages
    printf("Installing required packages...\n");
    status = system("apt-get install package1 package2 package3");
    if(status != 0) {
        printf("Error installing packages.\n");
        exit(1);
    }

    // Configure firewall
    printf("Configuring firewall...\n");
    status = system("ufw allow ssh && ufw enable");
    if(status != 0) {
        printf("Error configuring firewall.\n");
        exit(1);
    }

    printf("System administration tasks completed successfully.\n");
    return 0;
}