//FormAI DATASET v1.0 Category: System administration ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Check if user is root
    if (getuid() != 0) {
        printf("ERROR: This program must be run as root.\n");
        return 1;
    }

    // Check if command line arguments are provided
    if (argc < 2) {
        printf("USAGE: %s <username>\n", argv[0]);
        return 2;
    }

    // Get username from command line argument
    char *username = argv[1];

    // Check if user exists
    if (system(NULL)) {
        // Check if user exists
        char cmd[50];
        sprintf(cmd, "id -u %s", username);
        int status = system(cmd);
        if (status != 0) {
            printf("ERROR: User \'%s\' does not exist.\n", username);
            return 3;
        }

        // Create home directory for user
        sprintf(cmd, "mkdir -p /home/%s", username);
        system(cmd);

        // Update ownership and permissions of home directory
        sprintf(cmd, "chown -R %s:%s /home/%s", username, username, username);
        system(cmd);
        sprintf(cmd, "chmod 700 /home/%s", username);
        system(cmd);

        // Add user to sudoers file
        sprintf(cmd, "echo \'%s ALL=(ALL) NOPASSWD: ALL\' >> /etc/sudoers", username);
        system(cmd);

        // Print success message
        printf("User \'%s\' has been added to the system.\n", username);
    } else {
        printf("ERROR: Command processor not available.\n");
        return 4;
    }

    return 0;
}